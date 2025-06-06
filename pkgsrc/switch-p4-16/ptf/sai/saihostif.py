################################################################################
 #  Copyright (C) 2024 Intel Corporation
 #
 #  Licensed under the Apache License, Version 2.0 (the "License");
 #  you may not use this file except in compliance with the License.
 #  You may obtain a copy of the License at
 #
 #  http://www.apache.org/licenses/LICENSE-2.0
 #
 #  Unless required by applicable law or agreed to in writing,
 #  software distributed under the License is distributed on an "AS IS" BASIS,
 #  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 #  See the License for the specific language governing permissions
 #  and limitations under the License.
 #
 #
 #  SPDX-License-Identifier: Apache-2.0
################################################################################

# saihostif.${name_test}
#
# ARPTest
# DHCPTest
# LLDPTest
# BGPTest
# LACPTest
# SNMPTest
# SSHTest
# IP2METest
# TTLErrorTest
#ptf --test-dir PTF_TEST_CASES saihostif.DHCPTest  --qlen=10000 --platform nn -t "server='10.3.147.47';test_port=3;port_map_file='default_interface_to_front_map.ini';verbose=True;" --device-socket 0-3@tcp://127.0.0.1:10900 --device-socket 1-3@tcp://10.3.147.47:10900

import ptf
from ptf.base_tests import BaseTest
from ptf import config
import ptf.testutils as testutils
from ptf.testutils import *
from ptf.packet import *
from ptf.dataplane import match_exp_pkt
import datetime
import subprocess
#from switch import *
import sai_base_test

import switchsai_thrift.switch_sai_rpc as switch_sai_rpc
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
import time
from ptf import config
from ptf.testutils import *
from ptf.packet import *
from ptf.thriftutils import *
from switchsai_thrift.sai_headers import  *
from switch_utils import *
import pprint

this_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(this_dir, '..'))
from common.pktpy_utils import pktpy_skip # noqa pylint: disable=wrong-import-position


class ControlPlaneBaseTest(sai_base_test.ThriftInterfaceDataPlane):
    MAX_PORTS = 32
    POLICER_CIR = 32000
    POLICER_PIR = 32000
    PKT_TX_COUNT = 15

    my_ip = "172.16.0.1"
    peer_ip = "172.16.0.0"
    src_mac_uc = '00:55:55:55:55:00'

    hif_trap_list = []

    trap_list = [
        SAI_HOSTIF_TRAP_TYPE_TTL_ERROR,
        SAI_HOSTIF_TRAP_TYPE_BGP,
        SAI_HOSTIF_TRAP_TYPE_LACP,
        SAI_HOSTIF_TRAP_TYPE_ARP_REQUEST,
        SAI_HOSTIF_TRAP_TYPE_ARP_RESPONSE,
        SAI_HOSTIF_TRAP_TYPE_LLDP,
        SAI_HOSTIF_TRAP_TYPE_DHCP,
        SAI_HOSTIF_TRAP_TYPE_IP2ME
        ]

    myip = ''
    peerip = ''
    hostif_id={}
    traps=[]
    trap_groups=[]
    policers=[]
    routes=[]
    next_hops=[]
    rifs=[]
    v_routers=[]
    neighbors=[]
    br_ports=[]

    test_port_ind = 1
    hif_type = SAI_HOSTIF_TYPE_NETDEV

    def create_host_interfaces(self):
        for interface,front in interface_to_front_mapping.iteritems():
            port_id = port_list[int(interface)]
            hif_id = sai_thrift_create_hostif(self.client, self.hif_type, port_id, front)
            self.hostif_id[front]=hif_id
        return

    def __init__(self):
        BaseTest.__init__(self)

        self.test_params = testutils.test_params_get()

        self.myip = self.my_ip
        self.peerip = self.peer_ip
        return

    def setup_test_port_rif(self, port_ind):
        port = port_list[port_ind]
        v4_enabled = 1
        v6_enabled = 1

        vr_id = sai_thrift_get_default_router_id(self.client)
        sai_thrift_remove_default_bridge_ports(self.client, [port])
        self.br_ports.append(port)
        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port, 0, v4_enabled, v6_enabled, router_mac)
        self.rifs.append(rif_id1)
        return (vr_id, rif_id1)

    def setup_direct_route(self, vr_id, rif_id1, ip_addr):

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = ip_addr
        ip_addr1_subnet = ip_addr
        ip_mask1 = '255.255.255.254'
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
        route_data=[vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1]
        self.routes.append(route_data)

        return

    def setup_ip2me_route(self, ip_addr):

        default_router_id = sai_thrift_get_default_router_id(self.client)
        router_packet_action = SAI_PACKET_ACTION_FORWARD
        cpu_port_next_hop = sai_thrift_get_cpu_port_id(self.client)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1_subnet = ip_addr
        ip_mask1 = '255.255.255.255'
        sai_thrift_create_route(self.client, default_router_id, addr_family, ip_addr1_subnet, ip_mask1, cpu_port_next_hop, router_packet_action)
        route_data=[default_router_id, addr_family, ip_addr1_subnet, ip_mask1, cpu_port_next_hop]
        self.routes.append(route_data)
        return

    def create_routes(self):
        self.setup_ip2me_route(self.peerip)
        vr_id, rif_id = self.setup_test_port_rif(self.test_port_ind)
        self.setup_direct_route(vr_id, rif_id, self.peerip)
        return

    def setUp(self):

        ThriftInterfaceDataPlane.setUp(self)
        self.hostif_id = {}
        self.policers=[]
        self.traps=[]
        self.trap_groups=[]
        self.routes=[]
        self.next_hops=[]
        self.rifs=[]
        self.v_routers=[]
        self.neighbors=[]
        self.br_ports=[]

        switch_init(self.client)
        self.create_host_interfaces()

        if self.test_params['test_port'] != None:
            self.test_port_ind = self.test_params['test_port']

        for interface,front in interface_to_front_mapping.iteritems():
            port_id = port_list[int(interface)]
            self.dataplane.port_add(front, 1, int(interface))

        #self.dataplane.port_up(1, self.test_port_ind)
        time.sleep(10)

        return

    def tearDown(self):
        if config["log_dir"] != None:
            self.dataplane.stop_pcap()

        for interface,front in interface_to_front_mapping.iteritems():
            self.dataplane.port_remove(1, int(interface))

        for trap in self.traps:
            sai_thrift_remove_hostif_trap(self.client, trap)

        for trap_group in self.trap_groups:
            sai_thrift_remove_hostif_trap_group(self.client, trap_group)

        for policer in self.policers:
            self.client.sai_thrift_remove_policer(thrift_policer_id=policer)

        for route_data in self.routes:
            sai_thrift_remove_route(self.client,route_data[0],route_data[1],route_data[2],route_data[3],route_data[4])

        for neighbor_data in self.neighbors:
            sai_thrift_remove_neighbor(self.client, neighbor_data[0], neighbor_data[1], neighbor_data[2], neighbor_data[3])

        for nhop in self.next_hops:
            self.client.sai_thrift_remove_next_hop(nhop)

        for rif in self.rifs:
            self.client.sai_thrift_remove_router_interface(rif)

        for port in self.br_ports:
            sai_thrift_create_default_bridge_ports(self.client, [port])

        for v_router in self.v_routers:
            self.client.sai_thrift_remove_virtual_router(v_router)

        for interface,front in interface_to_front_mapping.iteritems():
            self.client.sai_thrift_remove_hostif(self.hostif_id[front])

        ThriftInterfaceDataPlane.tearDown(self)
        return

    def copp_test(self, packet, count, send_intf, recv_intf):
        start_time=datetime.datetime.now()
        for i in xrange(count):
            testutils.send_packet(self, send_intf, packet)

        end_time=datetime.datetime.now()
        total_rcv_pkt_cnt = count_matched_packets(self, packet, recv_intf[1], recv_intf[0], timeout=4)
        print total_rcv_pkt_cnt
        time_delta = end_time - start_time
        time_delta_ms = (time_delta.microseconds + time_delta.seconds * 10**6) / 10**3
        if time_delta_ms == 0:
            time_delta_ms = 1

        tx_pps = int(count/(float(time_delta_ms)/1000))
        rx_pps = int(total_rcv_pkt_cnt/(float(time_delta_ms)/1000))
        return total_rcv_pkt_cnt, time_delta, time_delta_ms, tx_pps, rx_pps

    def copp_stat_test(self, packet, count, send_intf):
        green_count = 0
        yellow_count = 0
        red_count = 0
        for i in xrange(count):
            testutils.send_packet(self, send_intf, packet)
        time.sleep(10)

        for policer in self.policers:
            green, yellow, red = self.client.sai_thrift_get_policer_stats(policer,[SAI_POLICER_STAT_GREEN_PACKETS,SAI_POLICER_STAT_YELLOW_PACKETS, SAI_POLICER_STAT_RED_PACKETS])
            green_count+=green
            yellow_count+=yellow
            red_count+=red
        return green_count, yellow_count, red_count

    def contruct_packet(self):
        raise NotImplemented

    def check_constraints(self, total_rcv_pkt_cnt, time_delta_ms, rx_pps):
        raise NotImplemented

    def one_port_test(self, port_number, packet_count):
        packet = self.contruct_packet()
        total_rcv_pkt_cnt, time_delta, time_delta_ms, tx_pps, rx_pps = self.copp_test(packet, packet_count, (0, port_number), (1, port_number))

        self.printStats(packet_count,
                        total_rcv_pkt_cnt,
                        time_delta,
                        tx_pps,
                        rx_pps)
        self.check_constraints(total_rcv_pkt_cnt)
        return

    def one_port_stat_test(self, port_number, packet_count):
        pkt_sent = 0
        packet = self.contruct_packet()
        green_count, yellow_count, red_count = self.copp_stat_test(packet, packet_count, (0, port_number))

        pkt_sent += packet_count
        self.check_stats(green_count, yellow_count, red_count, pkt_sent)
        self.printCoppStats(pkt_sent,
                            green_count,
                            yellow_count,
                            red_count)

        packet = self.contruct_packet2()
        green_count, yellow_count, red_count = self.copp_stat_test(packet, packet_count, (0, port_number))

        pkt_sent += packet_count
        self.check_stats(green_count, yellow_count, red_count, pkt_sent)
        self.printCoppStats(pkt_sent,
                            green_count,
                            yellow_count,
                            red_count)
        return

    def run_suite(self):
        raise NotImplemented

    def printCoppStats(self, pkt_send_count, green_count, yellow_count, red_count):
        if not(('verbose' in self.test_params) and (self.test_params['verbose'] == True)):
            return
        print 'test stats'
        print 'Packets sent = %d' % pkt_send_count
        print 'Packets marked green = %d' % green_count
        print 'Packets marked green = %d' % yellow_count
        print 'Packets marked red = %d' % red_count

        return

    def printStats(self, pkt_send_count, total_rcv_pkt_cnt, time_delta, tx_pps, rx_pps):
        if not(('verbose' in self.test_params) and (self.test_params['verbose'] == True)):
            return
        print 'test stats'
        print 'Packet sent = %10d' % pkt_send_count
        print 'Packet rcvd = %10d' % total_rcv_pkt_cnt
        print 'Test time = %s' % str(time_delta)
        print 'TX PPS = %d' % tx_pps
        print 'RX PPS = %d' % rx_pps

        return

class NoPolicyTest(ControlPlaneBaseTest):
    def __init__(self):
        ControlPlaneBaseTest.__init__(self)

    def run_suite(self):
        self.one_port_test(self.test_port_ind, 1)

    def check_constraints(self, total_rcv_pkt_cnt):
        assert(total_rcv_pkt_cnt == 1)

class PolicyTest(ControlPlaneBaseTest):
    def __init__(self):
        ControlPlaneBaseTest.__init__(self)

    def check_constraints(self, total_rcv_pkt_cnt):
        print total_rcv_pkt_cnt, self.POLICER_CIR
        #assert(self.POLICER_CIR*0.5 <= total_rcv_pkt_cnt <= self.POLICER_CIR*1.5)

    def check_stats(self, green_count, yellow_count, red_count, packet_count):
        if ((green_count+red_count+yellow_count)!=packet_count):
            raise Exception('policer stats not correct')

    def run_suite(self):
        self.one_port_test(self.test_port_ind, self.PKT_TX_COUNT)

    def run_stat_suite(self):
        self.one_port_stat_test(self.test_port_ind, self.PKT_TX_COUNT)

@group('hostif')
class ARPTest(PolicyTest):
    def __init__(self):
        PolicyTest.__init__(self)

    def runTest(self):
        self.run_suite()

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.setup_test_port_rif(self.test_port_ind)

        sai_policer_id = sai_thrift_create_policer(self.client,
                                                   meter_type=SAI_METER_TYPE_BYTES,
                                                   mode=SAI_POLICER_MODE_SR_TCM,
                                                   cir=self.POLICER_CIR,
                                                   cbs=0,
                                                   pir=0,
                                                   pbs=0,
                                                   red_action=SAI_PACKET_ACTION_DROP)
        self.policers.append(sai_policer_id)

        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4, policer_id=None)
        sai_thrift_set_hostif_trap_group_attribute(self.client, trap_group = trap_group, policer_id = sai_policer_id)
        self.trap_groups.append(trap_group)

        trap1 = sai_thrift_create_hostif_trap(client=self.client,
                                              trap_type=SAI_HOSTIF_TRAP_TYPE_ARP_RESPONSE,
                                              packet_action=SAI_PACKET_ACTION_TRAP,
                                              trap_group=trap_group)
        self.traps.append(trap1)

        trap2 = sai_thrift_create_hostif_trap(client=self.client,
                                              trap_type=SAI_HOSTIF_TRAP_TYPE_ARP_REQUEST,
                                              packet_action=SAI_PACKET_ACTION_TRAP,
                                              trap_group=trap_group)
        self.traps.append(trap2)

        return

    def contruct_packet(self):
        src_mac = self.src_mac_uc
        src_ip = self.myip
        dst_ip = self.peerip

        packet = simple_arp_packet(eth_dst='ff:ff:ff:ff:ff:ff',
                                   eth_src=src_mac,
                                   arp_op=1,
                                   ip_snd=src_ip,
                                   ip_tgt=dst_ip,
                                   hw_snd=src_mac,
                                   hw_tgt='ff:ff:ff:ff:ff:ff')

        return packet

    def contruct_packet2(self):
        src_mac = self.src_mac_uc
        src_ip = self.myip
        dst_ip = self.peerip

        packet = simple_arp_packet(arp_op=2,
                                   eth_dst=router_mac, pktlen=100)

        return packet

    def tearDown(self):
        ControlPlaneBaseTest.tearDown(self)
        return

@group('copp-stats')
class CoppStatTest(ARPTest):
    def __init__(self):
        ARPTest.__init__(self)

    def runTest(self):
        self.run_stat_suite()

    def setUp(self):
        ARPTest.setUp(self)

    def tearDown(self):
        ARPTest.tearDown(self)
        return

@group('hostif')
class DHCPTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.setup_test_port_rif(self.test_port_ind)

        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_DHCP,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        src_mac = self.src_mac_uc
        packet = simple_udp_packet(pktlen=100,
                                   eth_dst='ff:ff:ff:ff:ff:ff',
                                   eth_src=src_mac,
                                   dl_vlan_enable=False,
                                   vlan_vid=0,
                                   vlan_pcp=0,
                                   dl_vlan_cfi=0,
                                   ip_src='0.0.0.0',
                                   ip_dst='255.255.255.255',
                                   ip_tos=0,
                                   ip_ttl=64,
                                   udp_sport=68,
                                   udp_dport=67,
                                   ip_ihl=None,
                                   ip_options=False,
                                   with_udp_chksum=True)

        return packet

@group('hostif')
class LLDPTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)
        return

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        sai_policer_id = sai_thrift_create_policer(self.client,
                                                   meter_type=SAI_METER_TYPE_BYTES,
                                                   mode=SAI_POLICER_MODE_SR_TCM,
                                                   cir=self.POLICER_CIR,
                                                   cbs=32000,
                                                   pir=self.POLICER_PIR,
                                                   pbs=32000,
                                                   red_action=SAI_PACKET_ACTION_DROP)
        self.policers.append(sai_policer_id)
        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4, policer_id = sai_policer_id)
        self.trap_groups.append(trap_group)
        

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_LLDP,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)
        return

    def runTest(self):
        self.run_suite()
        return

    def contruct_packet(self):

        src_mac = self.src_mac_uc
        packet = simple_eth_packet(eth_dst='01:80:c2:00:00:0e',
                                   eth_src=src_mac,
                                   pktlen=48,
                                   eth_type=0x88cc)
        return packet

@group('hostif')
class LACPTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_LACP,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        packet = simple_eth_packet(pktlen=14,
               eth_dst='01:80:c2:00:00:02',
               eth_type=0x8809) / (chr(0x01)+(chr(0x01)))

        return packet

@group('hostif')
class SNMPTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.setup_test_port_rif(self.test_port_ind)

        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_SNMP,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        src_mac = self.src_mac_uc
        packet = simple_udp_packet(eth_dst=router_mac,
                                   ip_dst=self.peerip,
                                   eth_src=src_mac,
                                   udp_dport=161)
        return packet


@pktpy_skip  # TODO bf-pktpy
@group('hostif')
class SSHSrcTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.create_routes()

        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_SSH,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        src_ip = self.myip
        dst_ip = self.peerip

        packet = simple_tcp_packet(eth_dst=router_mac,
                                   ip_dst=dst_ip,
                                   ip_src=src_ip,
                                   tcp_sport=22,
                                   tcp_dport=222)

        return packet


@pktpy_skip  # TODO bf-pktpy
@group('hostif')
class SSHDstTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.create_routes()

        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_SSH,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        src_ip = self.myip
        dst_ip = self.peerip

        packet = simple_tcp_packet(eth_dst=router_mac,
                                   ip_dst=dst_ip,
                                   ip_src=src_ip,
                                   tcp_sport=222,
                                   tcp_dport=22)

        return packet


@pktpy_skip  # TODO bf-pktpy
@group('hostif')
class IP2METest(NoPolicyTest):

    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUpIp2Me(self):
        self.create_routes()

        trap_group = sai_thrift_create_hostif_trap_group(self.client,
                                                         queue_id=4)
        self.trap_groups.append(trap_group)
        trap = sai_thrift_create_hostif_trap(self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_IP2ME,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)

        return

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.setUpIp2Me()
        return

    def tearDown(self):
        ControlPlaneBaseTest.tearDown(self)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        src_mac = self.src_mac_uc
        dst_ip = self.peerip

        packet = simple_tcp_packet(eth_src=src_mac,
                                   eth_dst=router_mac,
                                   ip_dst=dst_ip)

        return packet


@pktpy_skip  # TODO bf-pktpy
@group('hostif')
class TTLErrorTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)

        port1 = port_list[0]
        port2 = port_list[self.test_port_ind]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''
        self.src_ip = '192.168.0.1'
        self.ip_addr1 = '172.16.10.1'


        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_TTL_ERROR,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        self.v_routers.append(vr_id)

        sai_thrift_remove_default_bridge_ports(self.client, [port2])
        self.br_ports.append(port2)
        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        self.rifs.append(rif_id1)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1_subnet = '172.16.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, self.ip_addr1, dmac1)
        neighbor_data=[addr_family, rif_id1, self.ip_addr1, dmac1]
        self.neighbors.append(neighbor_data)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, self.ip_addr1, rif_id1)
        self.next_hops.append(nhop1)

        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
        route_data=[vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1]
        self.routes.append(route_data)
        return

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):

        packet = simple_tcp_packet(eth_dst=router_mac,
                                   eth_src='00:22:22:22:22:22',
                                   ip_dst=self.ip_addr1,
                                   ip_src=self.src_ip,
                                   ip_id=105,
                                   ip_ttl=1)
        return packet


@pktpy_skip  # TODO bf-pktpy
@group('hostif')
class BGPTest(NoPolicyTest):
    def __init__(self):
        NoPolicyTest.__init__(self)
        return

    def setUp(self):
        ControlPlaneBaseTest.setUp(self)
        self.create_routes()

        trap_group = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
        self.trap_groups.append(trap_group)

        trap = sai_thrift_create_hostif_trap(client=self.client,
                                             trap_type=SAI_HOSTIF_TRAP_TYPE_BGP,
                                             packet_action=SAI_PACKET_ACTION_TRAP,
                                             trap_group=trap_group)
        self.traps.append(trap)

    def runTest(self):
        self.run_suite()

    def contruct_packet(self):
        dst_ip = self.peerip
        packet = simple_tcp_packet(eth_dst=router_mac,
                                   ip_dst=dst_ip,
                                   tcp_dport=179)
        return packet

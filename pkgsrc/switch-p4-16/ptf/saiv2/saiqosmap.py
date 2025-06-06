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


"""
Thrift SAI QosMap interface tester
"""

from sai_base_test import *


# test DSCP stepping in the loop from 0 to 64
DSCP_TEST_STEP = 1

QOS_TYPE_DICT = {
    SAI_QOS_MAP_TYPE_DSCP_TO_TC: (
        "dscp", "tc"),
    SAI_QOS_MAP_TYPE_DSCP_TO_COLOR: (
        "dscp", "color"),
    SAI_QOS_MAP_TYPE_TC_TO_QUEUE: (
        "tc", "queue_index"),
    SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR: (
        "dot1p", "color"),
    SAI_QOS_MAP_TYPE_DOT1P_TO_TC: (
        "dot1p", "tc"),
    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_QUEUE: (
        "prio", "queue_index"),
    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP: (
        "prio", "pg"),
    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP: (
        "tc", "pg"),
    SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P: (
        "tc", "dot1p", "color"),
    SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP: (
        "tc", "dscp", "color")}


def combine_ingress_pfc_tc_to_pg_mapping(pfc_prio_list, pg_list, tc_pg_list):
    ''' Function creates mapping
        PFC PRIORITY -> PRIORITY GROUP based on pg and tc_pg mapping.
    Args:
        pfc_prio_list (list): pfc_prio list of elements
        pg_list (list): pg list of elements
        tc_pg_list (list): tc pg list of elements

    Returns:
        list: mapping list of pfc_prio to pg elements
    '''
    mapping = []
    for i in pfc_prio_list:
        mapping.append([pfc_prio_list[i], pg_list[tc_pg_list[i]]])
    return mapping


def verify_qos_map(client, qosmap_id, qos_type, key_list, data_list):
    ''' Function verifies the HW QosMap type and map_to_value_list
    Args:
        client (client): client
        qosmap_id (obj_id): qos map object id
        qos_type (uint): qos map type
        key_list (list): qos map key list
        data_list (list): qos map data list
    Returns:
        bool: True if succesfully verified
    '''

    result = True
    try:
        attr = sai_thrift_get_qos_map_attribute(
            client,
            qosmap_id,
            type=qos_type,
            map_to_value_list=sai_thrift_qos_map_list_t(
                count=100,
                maplist=[]))

        if attr['type'] != qos_type:
            print("WARNING unexpected qos_map_type=%d, expected %d"
                  % (attr['type'].count, qos_type))
            return False
        if len(key_list) != attr['map_to_value_list'].count:
            print(
                "WARNING unexpected map_to_value_list.count=%d, expected %d"
                % (attr['map_to_value_list'].count, len(key_list)))
            return False

        expected_key = QOS_TYPE_DICT[qos_type][0]
        expected_value = QOS_TYPE_DICT[qos_type][1]

        if len(QOS_TYPE_DICT[qos_type]) == 3:
            expected_key2 = QOS_TYPE_DICT[qos_type][2]

        for i, data in enumerate(attr['map_to_value_list'].maplist):
            key_dict = {"color": data.key.color,
                        "dscp": data.key.dscp,
                        "dot1p": data.key.dot1p,
                        "prio": data.key.prio,
                        "tc": data.key.tc}
            value_dict = {"color": data.value.color,
                          "dscp": data.value.dscp,
                          "dot1p": data.value.dot1p,
                          "pg": data.value.pg,
                          "prio": data.value.prio,
                          "tc": data.value.tc,
                          "queue_index": data.value.queue_index}
            if len(QOS_TYPE_DICT[qos_type]) == 2:
                if ((key_dict[expected_key] != key_list[i]) or
                        (value_dict[expected_value] != data_list[i])):
                    result = False
                    break
            elif len(QOS_TYPE_DICT[qos_type]) == 3:
                if ((key_dict[expected_key] != key_list[i][0]) or
                        (key_dict[expected_key2] != key_list[i][1]) or
                        (value_dict[expected_value] != data_list[i])):
                    result = False
                    break
            else:
                print("WARNING!!! - UNSUPPORTED qos type")
                result = False
                break

        return result

    finally:
        pass


def create_qos_map_to_value_list(map_type, key_list, data_list):
    ''' Creates the qos map value list
    Args:
        map_type (uint): qos map type
        key_list (list): qos map key list
        data_list (list): qos map data list

    Returns:
        list: qos map value list
    '''

    map_list = []
    i = 0

    if len(key_list) != len(data_list):
        print("WARNING length of both lists should be equal")
        return 0

    for qos_type_dict_key in QOS_TYPE_DICT:
        if ((map_type == qos_type_dict_key) and
                (len(QOS_TYPE_DICT[qos_type_dict_key]) == 2)):
            for key_list_data in key_list:
                value_list_data = data_list[i]
                mapping = sai_thrift_qos_map_t(
                    key=sai_thrift_qos_map_params_t(
                        **{QOS_TYPE_DICT[qos_type_dict_key][0]:
                           key_list_data}),
                    value=sai_thrift_qos_map_params_t(
                        **{QOS_TYPE_DICT[qos_type_dict_key][1]:
                           value_list_data}))
                map_list.append(mapping)
                i += 1

        elif ((map_type == qos_type_dict_key) and
              (len(QOS_TYPE_DICT[qos_type_dict_key]) == 3)):
            for key_list_data1, key_list_data2 in key_list:
                value_list_data = data_list[i]
                mapping = sai_thrift_qos_map_t(
                    key=sai_thrift_qos_map_params_t(
                        **{QOS_TYPE_DICT[qos_type_dict_key][0]:
                           key_list_data1,
                           QOS_TYPE_DICT[qos_type_dict_key][2]:
                           key_list_data2}),
                    value=sai_thrift_qos_map_params_t(
                        **{QOS_TYPE_DICT[qos_type_dict_key][1]:
                           value_list_data}))
                map_list.append(mapping)
                i += 1

    qos_map_list = sai_thrift_qos_map_list_t(count=len(map_list),
                                             maplist=map_list)

    return qos_map_list


def update_and_verify_qos_map(client,
                              mapid,
                              map_type,
                              key_list,
                              data_list):
    ''' updates and verifies the qos map object with
        the provided key and data value lists

    Args:
        client (client): RPC client
        mapid (obj_id) : qos map object id
        map_type (uint): qos map type
        key_list (list): qos map key list
        data_list (list): qos map data list

    Returns:
        bool: True if succesfully updated and verified
    '''

    if mapid == 0:
        print("WARNING mapid not valid")
        return False
    if len(key_list) != len(data_list):
        print("WARNING length of both lists should be equal")
        return False
    qos_map_list = create_qos_map_to_value_list(map_type, key_list, data_list)
    status = sai_thrift_set_qos_map_attribute(client,
                                              mapid,
                                              map_to_value_list=qos_map_list)
    if status != SAI_STATUS_SUCCESS:
        print("WARNING Failed to update qos_map attribute")
        return False

    if verify_qos_map(client, mapid, map_type, key_list,
                      data_list) is False:
        print("WARNING! failed to verify updated qos_map 0x%x" % (mapid))
        return False
    return True


def create_and_verify_qos_map(client, map_type, key_list, data_list,
                              verify=True):
    ''' creates and verifies the qos map object with
        the provided key and data value lists

    Args:
        client (client): RPC client
        map_type (uint): qos map type
        key_list (list): qos map key list
        data_list (list): qos map data list
        verify (bool): verify request if True

    Returns:
        obj_id: created object id or 0 if failed to create or verify
    '''

    if len(key_list) != len(data_list):
        print("WARNING length of both lists should be equal")
        return 0
    qos_map_list = create_qos_map_to_value_list(map_type, key_list,
                                                data_list)
    qos_map_id = sai_thrift_create_qos_map(client,
                                           type=int(map_type),
                                           map_to_value_list=qos_map_list)
    if (qos_map_id != 0) and verify:
        if verify_qos_map(client, qos_map_id, map_type, key_list,
                          data_list) is False:
            print("WARNING! failed to verify the qos_map 0x%x" % (qos_map_id))
            sai_thrift_remove_qos_map(client, qos_map_id)
            qos_map_id = 0
    return qos_map_id


class L2QosMapBaseClass(SaiHelperBase):
    """Verifies SAI bridge port flood test case"""

    def setUp(self):
        SaiHelperBase.setUp(self)

        self.bp_port_list = []
        self.vlan_member_list = []
        self.test_dev_ports = []
        self.test_ports = [self.port0, self.port1, self.port2, self.port3]
        self.dev_test_port_list = [
            self.dev_port0, self.dev_port1, self.dev_port2, self.dev_port3
        ]
        vlan_id = 1
        i = 0
        for port in self.test_ports:
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          port_vlan_id=vlan_id)

            bp_port = sai_thrift_create_bridge_port(
                self.client,
                bridge_id=self.default_1q_bridge,
                port_id=port,
                type=SAI_BRIDGE_PORT_TYPE_PORT,
                admin_state=True)
            setattr(self, 'port%d_bp' % (i), bp_port)
            self.bp_port_list.append(bp_port)

            vlan_member = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.default_vlan_id,
                bridge_port_id=bp_port,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)
            self.vlan_member_list.append(vlan_member)
            i += 1

    def getPortQueueIndexStats(self, port, index, qstats):
        ''' Returns the port queue index stats.
        Args:
            port (list): list of port object ids
            index (uint): port queue index
            qstats (list): list of requested port queue statistics

        Returns:
            uint: port queue counters statistics
        '''
        total_cnt = 0

        sai_list = sai_thrift_u32_list_t(count=100, uint32list=[])
        attr = sai_thrift_get_port_attribute(self.client,
                                             port,
                                             qos_queue_list=sai_list)
        queue_list = attr['qos_queue_list'].idlist
        queue = queue_list[index]
        attr = sai_thrift_get_queue_attribute(self.client, queue, index=True)
        self.assertTrue(attr['index'] == index, "Failed to get the queue")
        for q_stat in qstats:
            stats = sai_thrift_get_queue_stats(self.client, queue)
            total_cnt += stats[q_stat]
        return total_cnt

    def tearDown(self):
        sai_thrift_flush_fdb_entries(
            self.client,
            entry_type=SAI_FDB_FLUSH_ENTRY_TYPE_ALL)
        for vlan_member in self.vlan_member_list:
            sai_thrift_remove_vlan_member(self.client, vlan_member)
        for bp_port in self.bp_port_list:
            sai_thrift_remove_bridge_port(self.client, bp_port)
        for port in self.test_ports:
            sai_thrift_set_port_attribute(
                self.client, port, port_vlan_id=0)

        SaiHelperBase.tearDown(self)


class L3QosMapBaseClass(SaiHelperBase):
    ''' QOS Map Tests Base class '''

    def setUp(self):
        dmac0 = '00:11:22:33:44:06'
        dmac1 = '00:11:22:33:44:04'
        nhop_ip0 = '10.10.10.10'
        nhop_ip1 = '10.10.10.11'
        nhop_ip2 = '10.10.10.12'
        nhop_ip3 = '10.10.10.13'

        SaiHelperBase.setUp(self)
        self.ppg_list = [0] * 8
        self.test_case_name = ""
        self.test_mapping = [0] * 4
        self.test_dev_ports = []
        self.test_ports = [self.port0, self.port1, self.port2, self.port3]
        self.dev_test_port_list = [
            self.dev_port0, self.dev_port1, self.dev_port2, self.dev_port3
        ]
        self.port0_rif = sai_thrift_create_router_interface(
            self.client,
            type=SAI_ROUTER_INTERFACE_TYPE_PORT,
            virtual_router_id=self.default_vrf,
            port_id=self.port0,
            admin_v4_state=True,
            admin_v6_state=True)
        self.port1_rif = sai_thrift_create_router_interface(
            self.client,
            type=SAI_ROUTER_INTERFACE_TYPE_PORT,
            virtual_router_id=self.default_vrf,
            port_id=self.port1,
            admin_v4_state=True,
            admin_v6_state=True)
        self.port2_rif = sai_thrift_create_router_interface(
            self.client,
            type=SAI_ROUTER_INTERFACE_TYPE_PORT,
            virtual_router_id=self.default_vrf,
            port_id=self.port2,
            admin_v4_state=True,
            admin_v6_state=True)
        self.port3_rif = sai_thrift_create_router_interface(
            self.client,
            type=SAI_ROUTER_INTERFACE_TYPE_PORT,
            virtual_router_id=self.default_vrf,
            port_id=self.port3,
            admin_v4_state=True,
            admin_v6_state=True)
        # # test neighbor creation
        self.neighbor_entry0 = sai_thrift_neighbor_entry_t(
            self.switch_id, self.port0_rif, sai_ipaddress(nhop_ip0))
        sai_thrift_create_neighbor_entry(self.client,
                                         self.neighbor_entry0,
                                         dst_mac_address=dmac1)
        self.neighbor_entry1 = sai_thrift_neighbor_entry_t(
            self.switch_id, self.port1_rif, sai_ipaddress(nhop_ip1))
        sai_thrift_create_neighbor_entry(self.client,
                                         self.neighbor_entry1,
                                         dst_mac_address=dmac1)
        self.neighbor_entry2 = sai_thrift_neighbor_entry_t(
            self.switch_id, self.port2_rif, sai_ipaddress(nhop_ip2))
        sai_thrift_create_neighbor_entry(self.client,
                                         self.neighbor_entry2,
                                         dst_mac_address=dmac1)
        self.neighbor_entry3 = sai_thrift_neighbor_entry_t(
            self.switch_id, self.port3_rif, sai_ipaddress(nhop_ip3))
        sai_thrift_create_neighbor_entry(self.client,
                                         self.neighbor_entry3,
                                         dst_mac_address=dmac1)

        self.nhop1 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('10.10.10.11'),
            router_interface_id=self.port1_rif,
            type=SAI_NEXT_HOP_TYPE_IP)

        self.route_entry1 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('10.10.10.11/32'))
        sai_thrift_create_route_entry(self.client,
                                      self.route_entry1,
                                      next_hop_id=self.nhop1)

        # IPv6 route
        self.nhop0 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('10.10.10.1'),
            router_interface_id=self.port2_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        self.neighbor_entry6 = sai_thrift_neighbor_entry_t(
            rif_id=self.port2_rif, ip_address=sai_ipaddress('10.10.10.1'))
        sai_thrift_create_neighbor_entry(self.client,
                                         self.neighbor_entry6,
                                         dst_mac_address=dmac0)
        self.route_entry1_ipv6 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf,
            destination=sai_ipprefix(
                '1234:5678:9abc:def0:4422:1133:5577:1111/128'))
        sai_thrift_create_route_entry(self.client,
                                      self.route_entry1_ipv6,
                                      next_hop_id=self.nhop0)

    def getPortQueueIndexStats(self, port, index, qstats):
        ''' Returns the port queue index stats.
        Args:
            port (list): list of port object ids
            index (uint): port queue index
            qstats (list): list of requested port queue statistics

        Returns:
            uint: port queue counters statistics
        '''
        total_cnt = 0

        sai_list = sai_thrift_u32_list_t(count=100, uint32list=[])
        attr = sai_thrift_get_port_attribute(self.client,
                                             port,
                                             qos_queue_list=sai_list)
        queue_list = attr['qos_queue_list'].idlist
        queue = queue_list[index]
        attr = sai_thrift_get_queue_attribute(self.client, queue, index=True)
        self.assertTrue(attr['index'] == index, "Failed to get the queue")
        for q_stat in qstats:
            stats = sai_thrift_get_queue_stats(self.client, queue)
            total_cnt += stats[q_stat]
        return total_cnt

    def getQueueStats(self, queues, qstats):
        ''' Returns the queue stats.
        Args:
            queues (list): list of queue object ids
            qstats (list): list of requested queue statistics

        Returns:
            uint: queue counters statistics
        '''
        total_cnt = 0
        for queue_oid in queues:
            stats = sai_thrift_get_queue_stats(self.client, queue_oid)
            for q_stat in qstats:
                total_cnt += stats[q_stat]
        return total_cnt

    def comparePortPPGStats(self, stats1, stats2):
        ''' Compares the tro ppg stats.
        Args:
            stats1 (list): stats 1 to be compared
            stats2 (list): stats 2 to be compared with stats 1

        Returns:
            bool: True if stats are equal.
        '''
        for port in range(0, len(self.test_dev_ports)):
            for ppg in range(8):
                if stats1[port][ppg] != stats2[port][ppg]:
                    print("comparePortPPGStats")
                    print("expected:", stats1)
                    print("received:", stats2)
                    print("PORT%d ppg=%d" % (port, ppg), "stats1[port][ppg]=",
                          stats1[port][ppg], "stats2[port][ppg])=",
                          stats2[port][ppg])
                    print("Not Equal")
                    return False
        return True

    def getPortPPGStats(self, ports):
        ''' Returns the prority groups ingress stats
            for given ports.
        Args:
            ports (list): list of dev port ids

        Returns:
            uint: ports priority group statistics
        '''
        stats = [0] * 4
        for port in range(0, len(ports)):
            stats[port] = [0] * 8
            for ppg in range(8):
                ppg_oid = self.ppg_list[port][ppg]
                cnt = self.getPpGroupStats(
                    [ppg_oid], ['SAI_INGRESS_PRIORITY_GROUP_STAT_PACKETS'])
                stats[port][ppg] = cnt
        return stats

    def getPpGroupStats(self, ppg_oids, ppg_stats):
        ''' Returns the prority groups stats
            for priority group object ids.
        Args:
            ppg_oids (list): list of priority group object ids
            ppg_stats (list): requested list of stats to be returned

        Returns:
            uint: ports priority group statistics
        '''

        total_cnt = 0

        for ppg_oid in ppg_oids:
            stats = sai_thrift_get_ingress_priority_group_stats(
                self.client, ppg_oid)
            for ppg_stat in ppg_stats:
                total_cnt += stats[ppg_stat]
        return total_cnt

    def setPortMultipleQosMapIds(self,
                                 port,
                                 qos_map_dict):
        ''' Sets the multiple qos map ids attributes
            for a given port.

        Args:
            port (obj_id): port object id
            qos_map_dict (dict): qos map object ids dictionary
        '''

        params = [
            'qos_pfc_priority_to_priority_group_map', 'qos_dot1p_to_tc_map',
            'qos_tc_to_priority_group_map', 'qos_dscp_to_tc_map',
            'qos_pfc_priority_to_queue_map'
        ]
        for key in qos_map_dict:
            for p in params:
                setattr(self, 't_%s' % p, None)

            temp_name = 't_' + key
            if key == 'qos_pfc_priority_to_priority_group_map':
                setattr(self, temp_name, qos_map_dict[key])
            if key == 'qos_dot1p_to_tc_map':
                setattr(self, temp_name, qos_map_dict[key])
            if key == 'qos_tc_to_priority_group_map':
                setattr(self, temp_name, qos_map_dict[key])
            if key == 'qos_dscp_to_tc_map':
                setattr(self, temp_name, qos_map_dict[key])
            if key == 'qos_pfc_priority_to_queue_map':
                setattr(self, temp_name, qos_map_dict[key])

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=getattr(
                    self, 't_qos_tc_to_priority_group_map'),
                qos_pfc_priority_to_priority_group_map=getattr(
                    self, 't_qos_pfc_priority_to_priority_group_map'),
                qos_pfc_priority_to_queue_map=getattr(
                    self, 't_qos_pfc_priority_to_queue_map'),
                qos_dot1p_to_tc_map=getattr(self, 't_qos_dot1p_to_tc_map'),
                qos_dscp_to_tc_map=getattr(self, 't_qos_dscp_to_tc_map'))

    def tearDown(self):

        sai_thrift_remove_route_entry(self.client, self.route_entry1)
        sai_thrift_remove_route_entry(self.client, self.route_entry1_ipv6)
        sai_thrift_remove_next_hop(self.client, self.nhop0)
        sai_thrift_remove_next_hop(self.client, self.nhop1)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor_entry0)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor_entry1)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor_entry2)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor_entry3)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor_entry6)
        sai_thrift_remove_router_interface(self.client, self.port0_rif)
        sai_thrift_remove_router_interface(self.client, self.port1_rif)
        sai_thrift_remove_router_interface(self.client, self.port2_rif)
        sai_thrift_remove_router_interface(self.client, self.port3_rif)

        SaiHelperBase.tearDown(self)


class L3QosDscpToTcTest(L3QosMapBaseClass):
    """ L3 Test qos map Dscp to Tc Test attributes """

    def setUp(self):
        L3QosMapBaseClass.setUp(self)

    def l3IPv4QosVariousDscpToTcMappingManyPortsTest(self):
        '''
        L3 IPv4 DSCP to TC mapping for various ingress ports test.
        '''

        print("l3IPv4QosVariousDscpToTcMappingManyPortsTest")

        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 1,
            'queue': 1
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 0,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 1,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 2,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 3,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 4,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 5,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 6,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 7,
            'tc': 3,
            'queue': 3
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 0,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 1,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 2,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 3,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 4,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 5,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 6,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 7,
            'tc': 5,
            'queue': 5
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        # fall info default tc
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })

        egress_ports = [self.port1]
        try:
            # setup dscp to tc mapping
            # Port 0 qos map
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 0, 0, 0, 1, 1, 1, 1]
            p0_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            # Verify QosMap value list
            self.assertTrue(p0_qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # Port 2 qos map
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [2, 2, 2, 2, 3, 3, 3, 3]
            p2_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(p2_qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # Port 3 qos map
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [4, 4, 4, 4, 5, 5, 5, 5]
            p3_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(p3_qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")
            # setup Port 1 tc to queue index mapping
            p1_ingress_tc_list = [0, 1, 2, 3, 4, 5]
            p1_ingress_queue_list = [0, 1, 2, 3, 4, 5]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, p1_ingress_tc_list,
                p1_ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # SET Port 0 dscp to TC mapping
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port0,
                qos_dscp_to_tc_map=p0_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port0,
                                                 qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             p0_qos_dscp_to_tc_map_id)
            # SET Port 2 dscp to TC mapping
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port2,
                qos_dscp_to_tc_map=p2_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port2,
                                                 qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             p2_qos_dscp_to_tc_map_id)

            # SET Port 3 dscp to TC mapping
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port3,
                qos_dscp_to_tc_map=p3_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port3,
                                                 qos_dscp_to_tc_map=True,
                                                 qos_tc_to_queue_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             p3_qos_dscp_to_tc_map_id)

            for port in egress_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)

            for test in test_cases:
                ip_tos = test['dscp'] << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (ip_tos=%d) ->"
                      " port %d (tc=%d => queue=%d)"
                      % (test['tx_port'], ip_tos, self.dev_port1, test['tc'],
                         test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port1)

                post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in self.test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, p0_qos_dscp_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p2_qos_dscp_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p3_qos_dscp_to_tc_map_id)

    def l3IPv4QosSameDscpToTcMappingManyPortsTest(self):
        '''
        L3 IPv4 same DSCP to TC mapping for various ingress ports test.
        '''

        print("l3IPv4QosSameDscpToTcMappingManyPortsTest")
        # default DSCP to TC mapping
        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 0,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 1,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 2,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 3,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 4,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 5,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 6,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 7,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port2,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 0,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 1,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 2,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 3,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 4,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 5,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 6,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 7,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        # fall info default mapping
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })

        ingress_ports = [self.port0, self.port2, self.port3]
        egress_ports = [self.port1]
        try:
            # setup dscp to tc mapping
            # Port 0, 2 and 3  qos map
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [7, 6, 5, 4, 3, 2, 1, 0]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup Port 1 tc to queue index mapping
            p1_ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            p1_ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, p1_ingress_tc_list,
                p1_ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            for port in ingress_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'],
                                 qos_dscp_to_tc_map_id)

            for port in egress_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)
            for test in test_cases:
                ip_tos = test['dscp'] << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (ip_tos=%d) ->"
                      " port %d (tc=%d => queue=%d)"
                      % (test['tx_port'], ip_tos, self.dev_port1, test['tc'],
                         test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port1)

                post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in self.test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def l3IPv4QosMapOneDscpToOneTcMappingTest(self):
        '''
        L3 IPv4 one DSCP to one TC mapping for ingress ports test.
        '''

        print("l3IPv4QosMapOneDscpToOneTcMappingTest")
        # default DSCP to TC mapping
        test_cases = []
        test_cases.append({'dscp': 0, 'tc': 0, 'queue': 0})
        test_cases.append({'dscp': 1, 'tc': 1, 'queue': 1})
        test_cases.append({'dscp': 2, 'tc': 2, 'queue': 2})
        test_cases.append({'dscp': 3, 'tc': 3, 'queue': 3})
        test_cases.append({'dscp': 4, 'tc': 4, 'queue': 4})
        test_cases.append({'dscp': 5, 'tc': 5, 'queue': 5})
        test_cases.append({'dscp': 6, 'tc': 6, 'queue': 6})
        test_cases.append({'dscp': 7, 'tc': 7, 'queue': 7})

        try:
            # setup dscp to tc mapping
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup tc to queue index mapping
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # set/get
            test_ports = [self.port0, self.port1]
            for port in [self.port0]:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'],
                                 qos_dscp_to_tc_map_id)

            for port in [self.port1]:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)

            for test in test_cases:
                ip_tos = test['dscp'] << 2
                pkt = simple_tcp_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ip_dst='10.10.10.11',
                    ip_src='192.168.0.1',
                    ip_tos=ip_tos,
                    ip_id=105,
                    ip_ttl=64)
                exp_pkt = simple_tcp_packet(
                    eth_dst='00:11:22:33:44:04',
                    eth_src=ROUTER_MAC,
                    ip_dst='10.10.10.11',
                    ip_src='192.168.0.1',
                    ip_tos=ip_tos,
                    ip_id=105,
                    ip_ttl=63)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (ip_tos=%d) ->"
                      " port %d (tc=%d, queue=%d)"
                      % (self.dev_port0, ip_tos, self.dev_port1, test['tc'],
                         test['queue']))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port1)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def l3IPv4QosMapMultipleDscpToSingleTcMappingTest(self):
        '''
        L3 IPv4 multiple DSCP to single TC mapping for ingress port test.
        '''

        print("l3IPv4QosMapMultipleDscpToSingleTcMappingTest")
        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 1,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 1,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 1,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 1,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 8,
            'tc': 6,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 9,
            'tc': 6,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 6,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 11,
            'tc': 6,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 12,
            'tc': 6,
            'queue': 0
        })

        try:
            # setup dscp to tc mapping
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [1, 1, 1, 1, 6, 6, 6, 6]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup tc to queue index mapping
            ingress_tc_list = [1, 6]
            ingress_queue_list = [2, 5]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # set/get
            ingress_ports = [self.port0, self.port2, self.port3]
            egress_ports = [self.port1]
            for port in ingress_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'],
                                 qos_dscp_to_tc_map_id)

            for port in egress_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)
            for test in test_cases:
                ip_tos = test['dscp'] << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (ip_tos=%d) ->"
                      " port %d (tc=%d => queue=%d)"
                      % (test['tx_port'], ip_tos, self.dev_port1, test['tc'],
                         test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port1)

                post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in self.test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def l3IPv6QosMapMultipleDscpToSingleTcMappingTest(self):
        '''
        L3 IPv6 multiple DSCP to single TC mapping for ingress port test.
        '''

        print("l3IPv6QosMapMultipleDscpToSingleTcMappingTest")

        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 6,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 9,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 11,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 12,
            'tc': 0,
            'queue': 0
        })
        try:
            # setup dscp to tc mapping
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [6, 6, 6, 6, 6, 6, 6, 6]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup tc to queue index mapping
            ingress_tc_list = [6]
            ingress_queue_list = [5]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # set/get
            test_ports = [self.port0, self.port2]
            for port in test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'],
                                 qos_dscp_to_tc_map_id)

                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)

            for test in test_cases:
                ipv6_tc = test['dscp'] << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (dscp=%d) ->"
                      " port %d (tc=%d queue=%d)"
                      % (test['tx_port'], test['dscp'], self.dev_port2,
                         test['tc'], test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def l3IPv6QosMapOneDscpToOneTcMappingTest(self):
        '''
        L3 IPv6 one DSCP to single TC mapping for ingress port test.
        '''

        print("l3IPv6QosMapOneDscpToOneTcMappingTest")

        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 8,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 9,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 11,
            'tc': 0,
            'queue': 0
        })  # default
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 12,
            'tc': 0,
            'queue': 0
        })  # default
        try:
            # setup dscp to tc mapping
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7, 9]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7, 1]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup tc to queue index mapping
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7, 1]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7, 1]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # set/get
            test_ports = [self.port0, self.port2]
            for port in test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'],
                                 qos_dscp_to_tc_map_id)

                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)

            for test in test_cases:
                ipv6_tc = test['dscp'] << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (dscp=%d) ->"
                      " port %d (tc=%d queue=%d)"
                      % (test['tx_port'], test['dscp'], self.dev_port2,
                         test['tc'], test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def l3IPv6QosSameDscpToTcMappingManyPortsTest(self):
        '''
        L3 IPv6 same DSCP to TC mapping for various ingress port test.
        '''

        print("l3IPv6QosSameDscpToTcMappingManyPortsTest")

        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 0,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 1,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 2,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 3,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 4,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 5,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 6,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 7,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 0,
            'tc': 0,
            'queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 1,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 2,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 3,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 4,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 5,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 6,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 7,
            'tc': 7,
            'queue': 7
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default

        try:
            # setup dscp to tc mapping
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup tc to queue index mapping
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            ingress_test_ports = [self.port0, self.port1, self.port3]
            egress_test_ports = [self.port2]
            for port in ingress_test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'],
                                 qos_dscp_to_tc_map_id)

            for port in egress_test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)

            for test in test_cases:
                ipv6_tc = test['dscp'] << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (dscp=%d) ->"
                      " port %d (tc=%d queue=%d)"
                      % (test['tx_port'], test['dscp'], self.dev_port2,
                         test['tc'], test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in self.test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def l3IPv6QosVariousDscpToTcMappingManyPortsTest(self):
        '''
        L3 IPv6 various DSCP to TC mapping for various ingress port test.
        '''

        print("l3IPv6QosVariousDscpToTcMappingManyPortsTest")

        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 0,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 1,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 2,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 3,
            'tc': 1,
            'queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 4,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 5,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 6,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 7,
            'tc': 2,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 0,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 1,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 2,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 3,
            'tc': 3,
            'queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 4,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 5,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 6,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 7,
            'tc': 4,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port1,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 0,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 1,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 2,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 3,
            'tc': 5,
            'queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 4,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 5,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 6,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 7,
            'tc': 6,
            'queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port3,
            'dscp': 10,
            'tc': 0,
            'queue': 0
        })  # default

        try:
            # setup dscp to tc mapping
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [1, 1, 1, 1, 2, 2, 2, 2]
            p0_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(p0_qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [3, 3, 3, 3, 4, 4, 4, 4]
            p1_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(p1_qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [5, 5, 5, 5, 6, 6, 6, 6]
            p3_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(p3_qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")

            # setup tc to queue index mapping
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # set/get
            egress_test_ports = [self.port2]
            # setup port 0
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port0,
                qos_dscp_to_tc_map=p0_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port0,
                                                 qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             p0_qos_dscp_to_tc_map_id)
            # setup port 1
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port1,
                qos_dscp_to_tc_map=p1_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port1,
                                                 qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             p1_qos_dscp_to_tc_map_id)
            # setup port 3
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port3,
                qos_dscp_to_tc_map=p3_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port3,
                                                 qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             p3_qos_dscp_to_tc_map_id)

            for port in egress_test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_to_queue_map=qos_tc_to_queue_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'],
                                 qos_tc_to_queue_map_id)

            for test in test_cases:
                ipv6_tc = test['dscp'] << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (dscp=%d) ->"
                      " port %d (tc=%d, queue=%d)"
                      % (test['tx_port'], test['dscp'], self.dev_port2,
                         test['tc'], test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            for port in self.test_ports:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=int(
                        SAI_NULL_OBJECT_ID))
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, p0_qos_dscp_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p1_qos_dscp_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p3_qos_dscp_to_tc_map_id)

    def l3IPv6QosMapDscpToTcDefaultMappingTest(self):
        '''
        L3 IPv6 DSCP to TC default mapping ingress port test.
        '''

        print("l3IPv6QosMapDscpToTcDefaultMappingTest")

        # default DSCP to TC mapping
        test_cases = []
        test_cases.append({'dscp': 0, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 1, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 2, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 3, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 4, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 5, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 6, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 7, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 10, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 12, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 0, 'port_default_tc': 1, 'queue': 1})
        test_cases.append({'dscp': 1, 'port_default_tc': 2, 'queue': 2})
        test_cases.append({'dscp': 2, 'port_default_tc': 3, 'queue': 3})
        test_cases.append({'dscp': 3, 'port_default_tc': 4, 'queue': 4})
        test_cases.append({'dscp': 4, 'port_default_tc': 5, 'queue': 5})
        test_cases.append({'dscp': 5, 'port_default_tc': 6, 'queue': 6})
        test_cases.append({'dscp': 6, 'port_default_tc': 7, 'queue': 7})
        test_cases.append({'dscp': 7, 'port_default_tc': 1, 'queue': 1})
        test_cases.append({'dscp': 10, 'port_default_tc': 1, 'queue': 1})
        test_cases.append({'dscp': 12, 'port_default_tc': 1, 'queue': 1})

        # setup tc -> queue mapping to make sure we always faii into default tc
        # = 0
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
        qos_tc_to_queue_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
            ingress_queue_list)
        self.assertTrue(qos_tc_to_queue_map_id != 0,
                        "Failed to create qos_map")

        status = sai_thrift_set_port_attribute(
            self.client,
            self.port2,
            qos_tc_to_queue_map=qos_tc_to_queue_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS,
                         "Failed to set port attribute")
        attr = sai_thrift_get_port_attribute(self.client,
                                             self.port2,
                                             qos_tc_to_queue_map=True)
        self.assertEqual(attr['qos_tc_to_queue_map'], qos_tc_to_queue_map_id)

        for port in [self.port0, self.port1, self.port2, self.port3]:
            attr = sai_thrift_get_port_attribute(self.client,
                                                 port,
                                                 qos_dscp_to_tc_map=True,
                                                 qos_default_tc=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'], 0)
            self.assertEqual(attr['qos_default_tc'], 0)
        try:
            for test in test_cases:
                ipv6_tc = test['dscp'] << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=ipv6_tc,
                    pktlen=100)
                # setup port default_tc
                status = sai_thrift_set_port_attribute(
                    self.client,
                    self.port0,
                    qos_default_tc=test['port_default_tc'])
                attr = sai_thrift_get_port_attribute(self.client,
                                                     self.port0,
                                                     qos_default_tc=True)
                self.assertEqual(attr['qos_default_tc'],
                                 test['port_default_tc'])

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (dscp=%d) ->"
                      " port %d (port_default_tc=%d queue=%d)"
                      % (self.dev_port0, test['dscp'], self.dev_port1,
                         test['port_default_tc'], test['queue']))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))

        finally:
            sai_thrift_set_port_attribute(self.client,
                                          self.port0,
                                          qos_default_tc=0)
            sai_thrift_set_port_attribute(
                self.client,
                self.port2,
                qos_tc_to_queue_map=int(SAI_NULL_OBJECT_ID))
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)

    def l3IPv4QosMapDscpToTcDefaultMappingTest(self):
        '''
        L3 IPv4 DSCP to TC default mapping for ingress port test.
        '''

        print("l3IPv4QosMapDscpToTcDefaultMappingTest")

        # default DSCP to TC mapping
        test_cases = []
        test_cases.append({'dscp': 0, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 1, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 2, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 3, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 4, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 5, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 6, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 7, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 8, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 32, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 16, 'port_default_tc': 0, 'queue': 0})
        test_cases.append({'dscp': 0, 'port_default_tc': 5, 'queue': 5})
        test_cases.append({'dscp': 1, 'port_default_tc': 5, 'queue': 5})
        test_cases.append({'dscp': 2, 'port_default_tc': 5, 'queue': 5})
        test_cases.append({'dscp': 3, 'port_default_tc': 5, 'queue': 5})
        test_cases.append({'dscp': 4, 'port_default_tc': 5, 'queue': 5})
        test_cases.append({'dscp': 5, 'port_default_tc': 7, 'queue': 7})
        test_cases.append({'dscp': 6, 'port_default_tc': 7, 'queue': 7})
        test_cases.append({'dscp': 7, 'port_default_tc': 7, 'queue': 7})
        test_cases.append({'dscp': 8, 'port_default_tc': 7, 'queue': 7})
        test_cases.append({'dscp': 32, 'port_default_tc': 7, 'queue': 7})
        test_cases.append({'dscp': 16, 'port_default_tc': 7, 'queue': 7})

        # setup tc to queue index mapping
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
        qos_tc_to_queue_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
            ingress_queue_list)
        self.assertTrue(qos_tc_to_queue_map_id != 0,
                        "Failed to create qos_map")

        status = sai_thrift_set_port_attribute(
            self.client,
            self.port1,
            qos_tc_to_queue_map=qos_tc_to_queue_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS,
                         "Failed to set port attribute")
        attr = sai_thrift_get_port_attribute(self.client,
                                             self.port1,
                                             qos_tc_to_queue_map=True)
        self.assertEqual(attr['qos_tc_to_queue_map'], qos_tc_to_queue_map_id)

        for port in [self.port0, self.port1, self.port2, self.port3]:
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 port,
                                                 qos_dscp_to_tc_map=True,
                                                 qos_default_tc=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'], 0)
            self.assertEqual(attr['qos_default_tc'], 0)
        try:
            for test in test_cases:
                ip_tos = test['dscp'] << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)
                # setup port default_tc
                status = sai_thrift_set_port_attribute(
                    self.client,
                    self.port0,
                    qos_default_tc=test['port_default_tc'])
                attr = sai_thrift_get_port_attribute(self.client,
                                                     self.port0,
                                                     qos_default_tc=True)
                self.assertEqual(attr['qos_default_tc'],
                                 test['port_default_tc'])

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (tos=%d) ->"
                      " port %d (port_default_tc=%d queue=%d)"
                      % (self.dev_port0, ip_tos, self.dev_port1,
                         test['port_default_tc'], test['queue']))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port1)
                post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
                print("\tok")

        finally:
            sai_thrift_set_port_attribute(self.client,
                                          self.port0,
                                          qos_default_tc=0)
            sai_thrift_set_port_attribute(
                self.client,
                self.port1,
                qos_tc_to_queue_map=int(SAI_NULL_OBJECT_ID))
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)

    def runTest(self):
        try:
            self.l3IPv4QosMapDscpToTcDefaultMappingTest()
            self.l3IPv6QosMapDscpToTcDefaultMappingTest()
            self.l3IPv4QosMapMultipleDscpToSingleTcMappingTest()
            self.l3IPv6QosMapMultipleDscpToSingleTcMappingTest()
            self.l3IPv4QosMapOneDscpToOneTcMappingTest()
            self.l3IPv6QosMapOneDscpToOneTcMappingTest()
            self.l3IPv4QosSameDscpToTcMappingManyPortsTest()
            self.l3IPv6QosSameDscpToTcMappingManyPortsTest()
            self.l3IPv4QosVariousDscpToTcMappingManyPortsTest()
            self.l3IPv6QosVariousDscpToTcMappingManyPortsTest()

        finally:
            pass

    def tearDown(self):

        L3QosMapBaseClass.tearDown(self)


class QosDscpToColorTest(L3QosMapBaseClass):
    ''' Qos DSCP to Color test class.
    '''

    def setUp(self):
        L3QosMapBaseClass.setUp(self)

        # setup dscp to tc mapping
        # map all 64 ingress dscps to tc=5 (can be any number)
        ingress_dscp_list = []
        ingress_tc_list = []
        ingress_color_list = []
        p1_ingress_color_list = []
        p2_ingress_color_list = []
        p3_ingress_color_list = []
        for dscp in range(0, 64):
            ingress_dscp_list.append(dscp)
            ingress_tc_list.append(5)
            color = int(dscp / 22)
            p1_color = (color + 1) % 3
            p2_color = (color + 2) % 3
            p3_color = (color + 3) % 3

            ingress_color_list.append(color)
            p1_ingress_color_list.append(p1_color)
            p2_ingress_color_list.append(p2_color)
            p3_ingress_color_list.append(p3_color)
        self.qos_dscp_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
            ingress_tc_list)
        self.assertTrue(self.qos_dscp_to_tc_map_id != 0,
                        "Failed to create qos_map")

        # setup dscp to color mapping
        # map all 64 ingress dscps to color = dscp / 22
        self.p0_qos_dscp_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_COLOR, ingress_dscp_list,
            ingress_color_list)
        self.assertTrue(self.p0_qos_dscp_to_color_map_id != 0,
                        "Failed to create qos_map")

        self.p1_qos_dscp_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_COLOR, ingress_dscp_list,
            p1_ingress_color_list)
        self.assertTrue(self.p1_qos_dscp_to_color_map_id != 0,
                        "Failed to create qos_map")
        self.p2_qos_dscp_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_COLOR, ingress_dscp_list,
            p2_ingress_color_list)
        self.assertTrue(self.p2_qos_dscp_to_color_map_id != 0,
                        "Failed to create qos_map")
        self.p3_qos_dscp_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_COLOR, ingress_dscp_list,
            p3_ingress_color_list)
        self.assertTrue(self.p3_qos_dscp_to_color_map_id != 0,
                        "Failed to create qos_map")

        # on egress lets map all tc with color red and yellow to 0
        # and all tc with color green to 63.
        egress_tc_color_list = [
            [0, 0],
            [1, 0],
            [2, 0],
            [3, 0],
            [4, 0],
            [5, 0],
            [6, 0],
            [7, 0],  # green
            [0, 1],
            [1, 1],
            [2, 1],
            [3, 1],
            [4, 1],
            [5, 1],
            [6, 1],
            [7, 1],  # yellow
            [0, 2],
            [1, 2],
            [2, 2],
            [3, 2],
            [4, 2],
            [5, 2],
            [6, 2],
            [7, 2],  # red
        ]
        egress_dscp_list = [
            63, 63, 63, 63, 63, 63, 63, 63,  # mapping green
            15, 15, 15, 15, 15, 15, 15, 15,  # mapping yellow
            11, 11, 11, 11, 11, 11, 11, 11,  # mapping red
        ]
        self.qos_tc_color_to_dscp_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
            egress_tc_color_list, egress_dscp_list)
        self.assertTrue(self.qos_tc_color_to_dscp_map_id != 0,
                        "Failed to create qos_map")

        # ingress settings
        # set Port 0 DSCP -> TC mapping
        status = sai_thrift_set_port_attribute(
            self.client,
            self.port0,
            qos_dscp_to_tc_map=self.qos_dscp_to_tc_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS,
                         "Failed to set port attribute")
        attr = sai_thrift_get_port_attribute(self.client,
                                             self.port0,
                                             qos_dscp_to_tc_map=True)
        self.assertEqual(attr['qos_dscp_to_tc_map'],
                         self.qos_dscp_to_tc_map_id)

        # egress settings
        # set the TC AND COLOR -> DSCP mapping
        # for port 1 for IPv4 and port2 for IPv6
        for port in [self.port1, self.port2]:
            # set Port 1 TC AND COLOR -> DSCP mapping
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_and_color_to_dscp_map=self.qos_tc_color_to_dscp_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(
                self.client, self.port1, qos_tc_and_color_to_dscp_map=True)
            self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                             self.qos_tc_color_to_dscp_map_id)

    def l3IPv4QosMapDscpToColorDefaultMappingTest(self):
        '''
        L3 IPv4 DSCP to COLOR default mapping for ingress port test.
        '''

        print("l3IPv4QosMapDscpToColorDefaultMappingTest")

        try:
            for ingress_dscp in range(0, 64):
                ingress_ip_tos = ingress_dscp << 2

                # only color green maps to dscp 63
                egress_ip_tos = 63 << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ingress_ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=egress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)

                # print("Sending IPv4 packet port %d (ip_tos=%d) ->"
                #       " port %d (ip_tos=%d)"
                #       % (self.dev_port0, ingress_ip_tos, self.dev_port1,
                #          egress_ip_tos))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port1)
                # print("\tok")

        finally:
            pass

    def l3IPv6QosMapDscpToColorDefaultMappingTest(self):
        '''
        L3 IPv6 DSCP to COLOR default mapping for ingress port test.
        '''
        print("l3IPv6QosMapDscpToColorDefaultMappingTest")

        try:
            for ingress_dscp in range(0, 64):
                # ingress_ip_tos = ingress_dscp << 2
                egress_dscp = 63
                ingress_ipv6_tc = ingress_dscp << 2
                egress_ipv6_tc = egress_dscp << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ingress_ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=egress_ipv6_tc,
                    pktlen=100)

                # print("Sending IPv6 packet port %d (ingress_dscp=%d) ->"
                #       " port %d (egress_dscp=%s)"
                #       % (self.dev_port0, ingress_dscp, self.dev_port2,
                #          egress_dscp))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port2)

        finally:
            pass

    def l3IPv4QosMapManyDscpToSameColorTest(self):
        '''
        L3 IPv4 many DSCP to same COLOR mapping for ingress port test.
        '''
        print("l3IPv4QosMapManyDscpToSameColorTest")

        try:
            # ingress settings
            # set Port 0 DSCP -> COLOR mapping
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port0,
                qos_dscp_to_color_map=self.p0_qos_dscp_to_color_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port0,
                                                 qos_dscp_to_color_map=True)
            self.assertEqual(attr['qos_dscp_to_color_map'],
                             self.p0_qos_dscp_to_color_map_id)

            for ingress_dscp in range(0, 64):
                ingress_ip_tos = ingress_dscp << 2
                # ingress_color = ingress_dscp / 22

                if ingress_dscp < 22:
                    egress_dscp = 63
                elif ingress_dscp < 44:
                    egress_dscp = 15
                else:
                    egress_dscp = 11
                egress_ip_tos = egress_dscp << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ingress_ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=egress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)

                # print("Sending IPv4 packet port %d (dscp=%d, ip_tos=%d,"
                #       " color=%d) -> port %d (dscp=%d, ip_tos=%d)"
                #       % (self.dev_port0, ingress_dscp, ingress_ip_tos,
                #          ingress_color, self.dev_port1, egress_dscp,
                #          egress_ip_tos))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port1)
                # print("\tok")

        finally:
            pass

    def l3IPv6QosMapManyDscpToSameColorTest(self):
        '''
        L3 IPv6 many DSCP to same COLOR mapping for ingress port test.
        '''
        print("l3IPv6QosMapManyDscpToSameColorTest")

        try:
            # ingress settings
            # set Port 0 DSCP -> COLOR mapping
            status = sai_thrift_set_port_attribute(
                self.client,
                self.port0,
                qos_dscp_to_color_map=self.p0_qos_dscp_to_color_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 self.port0,
                                                 qos_dscp_to_color_map=True)
            self.assertEqual(attr['qos_dscp_to_color_map'],
                             self.p0_qos_dscp_to_color_map_id)

            for ingress_dscp in range(0, 64):
                # ingress_color = ingress_dscp / 22

                if ingress_dscp < 22:
                    egress_dscp = 63
                elif ingress_dscp < 44:
                    egress_dscp = 15
                else:
                    egress_dscp = 11

                ingress_ipv6_tc = ingress_dscp << 2
                egress_ipv6_tc = egress_dscp << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ingress_ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=egress_ipv6_tc,
                    pktlen=100)

                # print("Sending IPv6 packet port %d (dscp=%d, ip_tos=%d,"
                #       " color=%d) -> port %d (dscp=%d, ip_tos=%d)"
                #       % (self.dev_port0, ingress_dscp, ingress_ipv6_tc,
                #          ingress_color, self.dev_port1, egress_dscp,
                #          egress_ipv6_tc))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                # print("\tok")

        finally:
            pass

    def l3IPv4QosMapSameDscpToColorManyIngressPortsTest(self):
        '''
        L3 IPv4 many DSCP to COLOR mapping for various ingress port test.
        '''
        print("l3IPv4QosMapSameDscpToColorManyIngressPortsTest")

        try:
            # ingress settings
            # set Port 0, 2, 3 DSCP -> COLOR mapping
            for port in [self.port0, self.port2, self.port3]:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_color_map=self.p0_qos_dscp_to_color_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dscp_to_color_map=True)
                self.assertEqual(attr['qos_dscp_to_color_map'],
                                 self.p0_qos_dscp_to_color_map_id)

            for port in [self.dev_port0, self.dev_port2, self.dev_port3]:
                for ingress_dscp in range(0, 64):
                    ingress_ip_tos = ingress_dscp << 2
                    # ingress_color = ingress_dscp / 22

                    if ingress_dscp < 22:
                        egress_dscp = 63
                    elif ingress_dscp < 44:
                        egress_dscp = 15
                    else:
                        egress_dscp = 11
                    egress_ip_tos = egress_dscp << 2
                    pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                            eth_src='00:22:22:22:22:22',
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ingress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=64)
                    exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                                eth_src=ROUTER_MAC,
                                                ip_dst='10.10.10.11',
                                                ip_src='192.168.0.1',
                                                ip_tos=egress_ip_tos,
                                                ip_id=105,
                                                ip_ttl=63)

                    # print("Sending IPv4 packet port %d (dscp=%d, ip_tos=%d, "
                    #       "color=%d) -> port %d (dscp=%d, ip_tos=%d)"
                    #     % (port, ingress_dscp, ingress_ip_tos, ingress_color,
                    #          self.dev_port1, egress_dscp, egress_ip_tos))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, self.dev_port1)
                    # print("\tok")

        finally:
            pass

    def l3IPv6QosMapSameDscpToColorManyIngressPortsTest(self):
        '''
        L3 IPv6 same DSCP to COLOR mapping for various ingress port test.
        '''
        print("l3IPv6QosMapSameDscpToColorManyIngressPortsTest")

        try:
            # ingress settings
            # set Port 0,1,3 DSCP -> COLOR mapping
            for port in [self.port0, self.port1, self.port3]:
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_color_map=self.p0_qos_dscp_to_color_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dscp_to_color_map=True)
                self.assertEqual(attr['qos_dscp_to_color_map'],
                                 self.p0_qos_dscp_to_color_map_id)

            for port in [self.dev_port0, self.dev_port1, self.dev_port3]:
                for ingress_dscp in range(0, 64):
                    #  ingress_color = ingress_dscp / 22

                    if ingress_dscp < 22:
                        egress_dscp = 63
                    elif ingress_dscp < 44:
                        egress_dscp = 15
                    else:
                        egress_dscp = 11

                    ingress_ipv6_tc = ingress_dscp << 2
                    egress_ipv6_tc = egress_dscp << 2
                    pkt = simple_tcpv6_packet(
                        eth_dst=ROUTER_MAC,
                        eth_src='00:22:22:22:22:22',
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=64,
                        ipv6_tc=ingress_ipv6_tc,
                        pktlen=100)
                    exp_pkt = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:06',
                        eth_src=ROUTER_MAC,
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=63,
                        ipv6_tc=egress_ipv6_tc,
                        pktlen=100)

                    # print("Sending IPv6 packet port %d (dscp=%d, ip_tos=%d,"
                    #       " color=%d) -> port %d (dscp=%d, ip_tos=%d)"
                    #       % (port, ingress_dscp, ingress_ipv6_tc,
                    #          ingress_color, self.dev_port1, egress_dscp,
                    #          egress_ipv6_tc))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, self.dev_port2)
                    # print("\tok")

        finally:
            pass

    def l3IPv4QosMapVariousDscpToColorManyIngressPortsTest(self):
        '''
        L3 IPv4 various DSCP to COLOR mapping for various ingress port test.
        '''
        print("l3IPv4QosMapVariousDscpToColorManyIngressPortsTest")

        try:
            # ingress settings
            # set Port 0, 2, 3 DSCP -> COLOR mapping
            for port, dscp_color in [
                    [self.port0, self.p0_qos_dscp_to_color_map_id],
                    [self.port2, self.p2_qos_dscp_to_color_map_id],
                    [self.port3, self.p3_qos_dscp_to_color_map_id]]:

                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_color_map=dscp_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dscp_to_color_map=True)
                self.assertEqual(attr['qos_dscp_to_color_map'], dscp_color)

            egress_port = self.dev_port1
            test_dev_port_list = [self.dev_port0, self.dev_port1,
                                  self.dev_port2, self.dev_port3]
            for p_idx, port in enumerate(test_dev_port_list):
                if port == egress_port:
                    continue
                for ingress_dscp in range(0, 64):

                    if ingress_dscp < 22:
                        egress_dscp_list = [63, 15, 11, 63]
                    elif ingress_dscp < 44:
                        egress_dscp_list = [15, 11, 63, 15]
                    else:
                        egress_dscp_list = [11, 63, 15, 11]

                    # ingress_color = ((ingress_dscp / 22) + p_idx) % 3
                    egress_dscp = egress_dscp_list[p_idx]

                    ingress_ip_tos = ingress_dscp << 2
                    egress_ip_tos = egress_dscp << 2

                    pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                            eth_src='00:22:22:22:22:22',
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ingress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=64)
                    exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                                eth_src=ROUTER_MAC,
                                                ip_dst='10.10.10.11',
                                                ip_src='192.168.0.1',
                                                ip_tos=egress_ip_tos,
                                                ip_id=105,
                                                ip_ttl=63)

                    # print("Sending IPv4 packet port %d (dscp=%d, ip_tos=%d,"
                    #       " color=%d) -> port %d (dscp=%d, ip_tos=%d)"
                    #     % (port, ingress_dscp, ingress_ip_tos, ingress_color,
                    #          egress_port, egress_dscp, egress_ip_tos))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, egress_port)
                    # print("\tok")

        finally:
            for port in [self.port0, self.port2, self.port3]:
                status = sai_thrift_set_port_attribute(self.client,
                                                       port,
                                                       qos_dscp_to_color_map=0)

    def l3IPv6QosMapVariousDscpToColorManyIngressPortsTest(self):
        '''
        L3 IPv6 various DSCP to COLOR mapping for various ingress port test.
        '''
        print("l3IPv6QosMapVariousDscpToColorManyIngressPortsTest")

        try:
            # ingress settings
            # set Port 0,1,3 DSCP -> COLOR mapping
            for port, dscp_color in [
                    [self.port0, self.p0_qos_dscp_to_color_map_id],
                    [self.port1, self.p1_qos_dscp_to_color_map_id],
                    [self.port3, self.p3_qos_dscp_to_color_map_id]]:

                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_color_map=dscp_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dscp_to_color_map=True)
                self.assertEqual(attr['qos_dscp_to_color_map'], dscp_color)

            egress_port = self.dev_port2
            test_dev_port_list = [self.dev_port0, self.dev_port1,
                                  self.dev_port2, self.dev_port3]
            for p_idx, port in enumerate(test_dev_port_list):
                if port == egress_port:
                    continue
                for ingress_dscp in range(0, 64):
                    if ingress_dscp < 22:
                        egress_dscp_list = [63, 15, 11, 63]
                    elif ingress_dscp < 44:
                        egress_dscp_list = [15, 11, 63, 15]
                    else:
                        egress_dscp_list = [11, 63, 15, 11]

                    # ingress_color = ((ingress_dscp / 22) + p_idx) % 3
                    ingress_ipv6_tc = ingress_dscp << 2
                    egress_dscp = egress_dscp_list[p_idx]
                    egress_ipv6_tc = egress_dscp << 2
                    pkt = simple_tcpv6_packet(
                        eth_dst=ROUTER_MAC,
                        eth_src='00:22:22:22:22:22',
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=64,
                        ipv6_tc=ingress_ipv6_tc,
                        pktlen=100)
                    exp_pkt = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:06',
                        eth_src=ROUTER_MAC,
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=63,
                        ipv6_tc=egress_ipv6_tc,
                        pktlen=100)

                    # print("Sending IPv6 packet port %d (dscp=%d, ip_tos=%d,"
                    #       " color=%d) -> port %d (dscp=%d, ip_tos=%d)"
                    #       % (port, ingress_dscp, ingress_ipv6_tc,
                    #          ingress_color, egress_port, egress_dscp,
                    #          egress_ipv6_tc))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, egress_port)
                    # print("\tok")

        finally:
            for port in [self.port0, self.port1, self.port3]:
                status = sai_thrift_set_port_attribute(self.client,
                                                       port,
                                                       qos_dscp_to_color_map=0)

    def runTest(self):
        try:
            self.l3IPv4QosMapDscpToColorDefaultMappingTest()
            self.l3IPv6QosMapDscpToColorDefaultMappingTest()
            self.l3IPv4QosMapManyDscpToSameColorTest()
            self.l3IPv6QosMapManyDscpToSameColorTest()
            self.l3IPv4QosMapSameDscpToColorManyIngressPortsTest()
            self.l3IPv6QosMapSameDscpToColorManyIngressPortsTest()
            self.l3IPv4QosMapVariousDscpToColorManyIngressPortsTest()
            self.l3IPv6QosMapVariousDscpToColorManyIngressPortsTest()

        finally:
            pass

    def tearDown(self):

        for port in [self.port0, self.port1, self.port2]:
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_dscp_to_tc_map=0)
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_tc_and_color_to_dscp_map=0)
        sai_thrift_remove_qos_map(self.client, self.qos_dscp_to_tc_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.qos_tc_color_to_dscp_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p0_qos_dscp_to_color_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p1_qos_dscp_to_color_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p2_qos_dscp_to_color_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p3_qos_dscp_to_color_map_id)

        L3QosMapBaseClass.tearDown(self)


class QosTcToPriorityGroupTestPFC(L3QosMapBaseClass):
    ''' QOS map TC to priority group test class
    '''

    def setUp(self):
        L3QosMapBaseClass.setUp(self)

        # setup dscp -> tc
        # testing QosTcToPriorityGroupTest
        # SAI_PORT_ATTR_QOS_DSCP_TO_TC_MAP
        # SAI_PORT_ATTR_QOS_PFC_PRIORITY_TO_PRIORITY_GROUP_MAP
        # setup tc -> tos
        # setup tos -> pgp

        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_pfc_to_queue_map_id = []

        ingress_key_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.qos_dscp_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_key_list,
            ingress_tc_list)
        self.assertTrue(self.qos_dscp_tc_map_id != 0,
                        "Failed to create qos_map")
        self.dot1_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_key_list,
            ingress_tc_list)
        self.assertTrue(self.dot1_to_tc_map_id != 0,
                        "Failed to create qos_map")

        self.ppg_list = []
        self.ppg_list = [0] * 8
        p = 0
        for port in [self.port0, self.port1, self.port2, self.port3]:
            self.ppg_list[p] = []
            for ppg_index in range(8):
                ppg = sai_thrift_create_ingress_priority_group(
                    self.client, port, ppg_index)
                self.assertNotEqual(ppg, 0, "Failed to create priority group")
                self.ppg_list[p].append(ppg)
            p += 1

            # verify number of ppg groups
            attr = sai_thrift_get_port_attribute(
                self.client, port, number_of_ingress_priority_groups=True)
            nbr_groups = attr['number_of_ingress_priority_groups']
            ingress_priority_group_list = sai_thrift_u32_list_t(
                count=nbr_groups, uint32list=[])
            attr = sai_thrift_get_port_attribute(
                self.client,
                port,
                ingress_priority_group_list=ingress_priority_group_list)
            self.assertTrue(
                attr['ingress_priority_group_list'].count == nbr_groups,
                "Failed to verify ingress priority groups")
            self.assertTrue(nbr_groups == 9,
                            "Failed to verify ingress priority groups")

        ingress_pfc_prio_list = [0]
        ingress_pg_list = [0]
        self.pfc_to_pg_map_id = [0] * 8
        test_dev_ports = [self.dev_port0, self.dev_port1,
                          self.dev_port2, self.dev_port3]

        for port in range(0, len(test_dev_ports)):
            self.pfc_to_pg_map_id[port] = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP,
                ingress_pfc_prio_list, ingress_pg_list)
            self.assertTrue(self.pfc_to_pg_map_id[port] != 0,
                            "Failed to create qos_map")

        self.tc_to_pg_map_id = [0] * 8
        ingress_tc_list = [0]
        ingress_pg_list = [0]
        for port in range(0, len(test_dev_ports)):
            self.tc_to_pg_map_id[port] = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                ingress_tc_list, ingress_pg_list)
            self.assertTrue(self.tc_to_pg_map_id[port] != 0,
                            "Failed to create qos_map")

        # test default IPv4 frame
        self.ipv4_pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                          eth_src='00:22:22:22:22:22',
                                          ip_dst='10.10.10.11',
                                          ip_src='192.168.0.1',
                                          ip_dscp=0,
                                          ip_id=105,
                                          ip_ttl=64)

        self.ipv6_pkt = simple_tcpv6_packet(
            eth_dst=ROUTER_MAC,
            eth_src='00:22:22:22:22:22',
            ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
            ipv6_src='2000::1',
            ipv6_hlim=64,
            ipv6_tc=0,
            pktlen=100)
        self.eth_pkt = simple_arp_packet(pktlen=60, vlan_vid=1, vlan_pcp=0)

    def tearDown(self):
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}
        try:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                self.setPortMultipleQosMapIds(
                    port,
                    qos_map_dict)

            sai_thrift_remove_qos_map(self.client, self.qos_dscp_tc_map_id)

        finally:
            i = 0
            test_dev_ports = [self.dev_port0, self.dev_port1, self.dev_port2,
                              self.dev_port3]
            for port in range(0, len(test_dev_ports)):
                sai_thrift_remove_qos_map(self.client,
                                          self.pfc_to_pg_map_id[port])
                sai_thrift_remove_qos_map(self.client,
                                          self.tc_to_pg_map_id[port])
                for ppg in self.ppg_list[port]:
                    sai_thrift_remove_ingress_priority_group(
                        self.client, ppg)
                    i += 1

            L3QosMapBaseClass.tearDown(self)

    def defaultNoPfcToPpgMappingIP(self):
        """
        Function configures the PFC to Priority Group test data
        for default No pfc -> ppg mapping test case
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # default test_case
        self.test_case_name = "default No pfc -> ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        # no port qos_map updated
        pfc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def defaultNoPfcToPpgMappingEth(self):
        """
        Function configures the PFC to Priority Group test data
        for default No pfc -> ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # default test_case
        self.test_case_name = "default No pfc -> ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        # no port qos_map updated
        pfc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def multiplePfcToSamePpgMappingIP(self):
        """
        Function configures the PFC to Priority Group test data
        for multiple pfc -> same ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # multiple pfc -> same ppg
        self.test_case_name = "multiple pfc -> same ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [3, 3, 3, 3, 5, 5, 5, 5]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def multiplePfcToSamePpgMappingEth(self):
        """
        Function configures the PFC to Priority Group test data
        for multiple pfc -> same ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # multiple pfc -> same ppg
        self.test_case_name = "multiple pfc -> same ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [3, 3, 3, 3, 5, 5, 5, 5]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def oneToOnePfcToPpgMappingIP(self):
        """
        Function configures the PFC to Priority Group test data
        for one to one pfc -> ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # one to one mapping
        self.test_case_name = "one to one pfc -> ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def oneToOnePfcToPpgMappingEth(self):
        """
        Function configures the PFC to Priority Group test data
        for one to one pfc -> ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # one to one mapping
        self.test_case_name = "one to one pfc -> ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def samePfcToPpgMapOnManyIngressPortsIPv4(self):
        """
        Function configures the PFC to Priority Group test data
        for same pfc -> ppg map on many ingress ports
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # same pfc -> ppg on different ingress ports
        self.test_case_name = "same pfc -> ppg map on many ingress ports"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [6, 4, 1, 0, 7, 5, 2, 3]
        pfc_pg_list[1] = pfc_pg_list[0]
        pfc_pg_list[2] = pfc_pg_list[0]
        pfc_pg_list[3] = pfc_pg_list[0]

        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_dev_ports = [
            self.dev_port0, self.dev_port1, self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[0]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def samePfcToPpgMapOnManyIngressPortsIPv6(self):
        """
        Function configures the PFC to Priority Group test data
        for same pfc -> ppg map on many ingress ports
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # same pfc -> ppg on different ingress ports
        self.test_case_name = "same pfc -> ppg map on many ingress ports"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [6, 4, 1, 0, 7, 5, 2, 3]
        pfc_pg_list[1] = pfc_pg_list[0]
        pfc_pg_list[2] = pfc_pg_list[0]
        pfc_pg_list[3] = pfc_pg_list[0]

        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_dev_ports = [
            self.dev_port0, self.dev_port1, self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[0]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def samePfcToPpgMapOnManyIngressPortsEth(self):
        """
        Function configures the PFC to Priority Group test data
        for same pfc -> ppg map on many ingress ports
        """
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # same pfc -> ppg on different ingress ports
        self.test_case_name = "same pfc -> ppg map on many ingress ports"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [6, 4, 1, 0, 7, 5, 2, 3]
        pfc_pg_list[1] = pfc_pg_list[0]
        pfc_pg_list[2] = pfc_pg_list[0]
        pfc_pg_list[3] = pfc_pg_list[0]

        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_dev_ports = [
            self.dev_port0, self.dev_port1, self.dev_port2, self.dev_port3
        ]

        for ingress_port in range(0, len(self.test_dev_ports)):
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[0]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def variousPfcToPpgMapOnManyIngressPortsIPv4(self):
        """
        Function configures the PFC to Priority Group test data
        for various pfc -> ppg map on many ingress ports
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # different pfc -> ppg on different ingress ports
        self.test_case_name = ("various pfc -> ppg map on many ingress " +
                               "ports")
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 0, 0, 0, 1, 1, 1, 1]
        pfc_pg_list[1] = [2, 2, 2, 2, 3, 3, 3, 3]
        pfc_pg_list[2] = [4, 4, 4, 4, 5, 5, 5, 5]
        pfc_pg_list[3] = [6, 6, 6, 6, 7, 7, 7, 7]

        # this mapping works on model
        pfc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[1] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[2] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[3] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            mapping = combine_ingress_pfc_tc_to_pg_mapping(
                pfc_list, pfc_pg_list[ingress_port], tc_pg_list)
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[ingress_port]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                ingress_port]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def variousPfcToPpgMapOnManyIngressPortsIPv6(self):
        """
        Function configures the PFC to Priority Group test data
        for various pfc -> ppg map on many ingress ports
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # different pfc -> ppg on different ingress ports
        self.test_case_name = ("various pfc -> ppg map on many ingress " +
                               "ports")
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 0, 0, 0, 1, 1, 1, 1]
        pfc_pg_list[1] = [2, 2, 2, 2, 3, 3, 3, 3]
        pfc_pg_list[2] = [4, 4, 4, 4, 5, 5, 5, 5]
        pfc_pg_list[3] = [6, 6, 6, 6, 7, 7, 7, 7]

        # this mapping works on model
        pfc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[1] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[2] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[3] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            mapping = combine_ingress_pfc_tc_to_pg_mapping(
                pfc_list, pfc_pg_list[ingress_port], tc_pg_list)
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[ingress_port]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                ingress_port]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def variousPfcToPpgMapOnManyIngressPortsEth(self):
        """
        Function configures the PFC to Priority Group test data
        for various pfc -> ppg map on many ingress ports
        """
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # different pfc -> ppg on different ingress ports
        self.test_case_name = ("various pfc -> ppg map on many ingress " +
                               "ports")
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 0, 0, 0, 1, 1, 1, 1]
        pfc_pg_list[1] = [2, 2, 2, 2, 3, 3, 3, 3]
        pfc_pg_list[2] = [4, 4, 4, 4, 5, 5, 5, 5]
        pfc_pg_list[3] = [6, 6, 6, 6, 7, 7, 7, 7]

        # this mapping works on model
        pfc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[1] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[2] = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[3] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            mapping = combine_ingress_pfc_tc_to_pg_mapping(
                pfc_list, pfc_pg_list[ingress_port], tc_pg_list)
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[ingress_port]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                ingress_port]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def noPfcToPpgMappingIPv4(self):
        """
        Function configures the PFC to Priority Group test data
        for no pfc -> ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # no pfc_ppg mapping defined
        self.test_case_name = "no pfc -> ppg mapping "
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]  # no pfc to ppg updated

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                print(key, ppg)
                ingress_ip_tos = key << 2
                pkts = 1 + port
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def noPfcToPpgMappingIPv6(self):
        """
        Function configures the PFC to Priority Group test data
        for no pfc -> ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # no pfc_ppg mapping defined
        self.test_case_name = "no pfc -> ppg mapping "
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]  # no pfc to ppg updated

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                print(key, ppg)
                ingress_ip_tos = key << 2
                pkts = 1 + port
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)

        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def noPfcToPpgMappingEth(self):
        """
        Function configures the PFC to Priority Group test data
        for no pfc -> ppg mapping
        """
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        pfc_pg_list = [0] * 4

        # no pfc_ppg mapping defined
        self.test_case_name = "no pfc -> ppg mapping "
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]  # no pfc to ppg updated

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list[0], tc_pg_list)
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            # for L2 set the SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            if pfc_pg_list[ingress_port] == 0:
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list), True,
                "Failed verify updated qos_map attribute")

        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue

            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                print(key, ppg)
                pkts = 1 + port
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def runTest(self):
        try:
            # PFC to Priority Group tests
            # Test case 1
            self.defaultNoPfcToPpgMappingIP()
            self.defaultNoPfcToPpgMappingEth()

            # Test case 2
            self.multiplePfcToSamePpgMappingIP()
            self.multiplePfcToSamePpgMappingEth()

            # Test case 3
            self.oneToOnePfcToPpgMappingIP()
            self.oneToOnePfcToPpgMappingEth()

            # Test case 4
            self.samePfcToPpgMapOnManyIngressPortsIPv4()
            self.samePfcToPpgMapOnManyIngressPortsIPv6()
            self.samePfcToPpgMapOnManyIngressPortsEth()

            # Test case 5
            self.variousPfcToPpgMapOnManyIngressPortsIPv4()
            self.variousPfcToPpgMapOnManyIngressPortsIPv6()
            self.variousPfcToPpgMapOnManyIngressPortsEth()

            # Test case 6
            self.noPfcToPpgMappingIPv4()
            self.noPfcToPpgMappingIPv6()
            self.noPfcToPpgMappingEth()

        finally:
            pass


class QosTcToPriorityGroupTestTC(L3QosMapBaseClass):
    ''' QOS map TC to priority group test class
    '''

    def setUp(self):
        L3QosMapBaseClass.setUp(self)

        # setup dscp -> tc
        # testing QosTcToPriorityGroupTest
        # SAI_PORT_ATTR_QOS_DSCP_TO_TC_MAP
        # SAI_PORT_ATTR_QOS_PFC_PRIORITY_TO_PRIORITY_GROUP_MAP
        # setup tc -> tos
        # setup tos -> pgp

        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_pfc_to_queue_map_id = []

        ingress_key_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.qos_dscp_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_key_list,
            ingress_tc_list)
        self.assertTrue(self.qos_dscp_tc_map_id != 0,
                        "Failed to create qos_map")
        self.dot1_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_key_list,
            ingress_tc_list)
        self.assertTrue(self.dot1_to_tc_map_id != 0,
                        "Failed to create qos_map")

        self.ppg_list = []
        self.ppg_list = [0] * 8
        p = 0
        for port in [self.port0, self.port1, self.port2, self.port3]:
            self.ppg_list[p] = []
            for ppg_index in range(8):
                ppg = sai_thrift_create_ingress_priority_group(
                    self.client, port, ppg_index)
                self.assertNotEqual(ppg, 0, "Failed to create priority group")
                self.ppg_list[p].append(ppg)
            p += 1

            # verify number of ppg groups
            attr = sai_thrift_get_port_attribute(
                self.client, port, number_of_ingress_priority_groups=True)
            nbr_groups = attr['number_of_ingress_priority_groups']
            ingress_priority_group_list = sai_thrift_u32_list_t(
                count=nbr_groups, uint32list=[])
            attr = sai_thrift_get_port_attribute(
                self.client,
                port,
                ingress_priority_group_list=ingress_priority_group_list)
            self.assertTrue(
                attr['ingress_priority_group_list'].count == nbr_groups,
                "Failed to verify ingress priority groups")
            self.assertTrue(nbr_groups == 9,
                            "Failed to verify ingress priority groups")

        ingress_pfc_prio_list = [0]
        ingress_pg_list = [0]
        self.pfc_to_pg_map_id = [0] * 8
        test_dev_ports = [self.dev_port0, self.dev_port1,
                          self.dev_port2, self.dev_port3]

        for port in range(0, len(test_dev_ports)):
            self.pfc_to_pg_map_id[port] = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP,
                ingress_pfc_prio_list, ingress_pg_list)
            self.assertTrue(self.pfc_to_pg_map_id[port] != 0,
                            "Failed to create qos_map")

        self.tc_to_pg_map_id = [0] * 8
        ingress_tc_list = [0]
        ingress_pg_list = [0]
        for port in range(0, len(test_dev_ports)):
            self.tc_to_pg_map_id[port] = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                ingress_tc_list, ingress_pg_list)
            self.assertTrue(self.tc_to_pg_map_id[port] != 0,
                            "Failed to create qos_map")

        # test default IPv4 frame
        self.ipv4_pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                          eth_src='00:22:22:22:22:22',
                                          ip_dst='10.10.10.11',
                                          ip_src='192.168.0.1',
                                          ip_dscp=0,
                                          ip_id=105,
                                          ip_ttl=64)

        self.exp_ipv4_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                              eth_src=ROUTER_MAC,
                                              ip_dst='10.10.10.11',
                                              ip_src='192.168.0.1',
                                              ip_dscp=0,
                                              ip_id=105,
                                              ip_ttl=63)

        self.ipv6_pkt = simple_tcpv6_packet(
            eth_dst=ROUTER_MAC,
            eth_src='00:22:22:22:22:22',
            ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
            ipv6_src='2000::1',
            ipv6_hlim=64,
            ipv6_tc=0,
            pktlen=100)

        self.exp_ipv6_pkt = simple_tcpv6_packet(
            eth_dst='00:11:22:33:44:06',
            eth_src=ROUTER_MAC,
            ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
            ipv6_src='2000::1',
            ipv6_hlim=63,
            ipv6_tc=0,
            pktlen=100)

        self.eth_pkt = simple_arp_packet(pktlen=60, vlan_vid=1, vlan_pcp=0)

        self.exp_eth_pkt = simple_arp_packet(pktlen=60, vlan_vid=1, vlan_pcp=0,
                                             eth_dst='ff:ff:ff:ff:ff:ff',
                                             eth_src='00:06:07:08:09:0a')

    def tearDown(self):
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}
        try:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                self.setPortMultipleQosMapIds(
                    port,
                    qos_map_dict)

            sai_thrift_remove_qos_map(self.client, self.qos_dscp_tc_map_id)

        finally:
            i = 0
            test_dev_ports = [self.dev_port0, self.dev_port1, self.dev_port2,
                              self.dev_port3]
            for port in range(0, len(test_dev_ports)):
                sai_thrift_remove_qos_map(self.client,
                                          self.pfc_to_pg_map_id[port])
                sai_thrift_remove_qos_map(self.client,
                                          self.tc_to_pg_map_id[port])
                for ppg in self.ppg_list[port]:
                    sai_thrift_remove_ingress_priority_group(
                        self.client, ppg)
                    i += 1

            L3QosMapBaseClass.tearDown(self)

    def defaultNoTcToPpgMappingIP(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for default No tc -> ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4

        self.test_case_name = "default No tc -> ppg mapping"
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)

        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)

        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def defaultNoTcToPpgMappingEth(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for default No tc -> ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4

        self.test_case_name = "default No tc -> ppg mapping"
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [0, 0, 0, 0, 0, 0, 0, 0]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)

        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def multipleTcToSamePpgMappingIP(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for multiple tc -> same ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # multiple tc -> same ppg
        self.test_case_name = "multiple tc -> same ppg mapping"
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [7, 7, 7, 7, 3, 3, 3, 3]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def multipleTcToSamePpgMappingEth(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for multiple tc -> same ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # multiple tc -> same ppg
        self.test_case_name = "multiple tc -> same ppg mapping"
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [7, 7, 7, 7, 3, 3, 3, 3]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def oneToOneTcToPpgMappingIP(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for one to one tc -> ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # one to one mapping
        self.test_case_name = "one to one tc -> ppg mapping"
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def oneToOneTcToPpgMappingEth(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for one to one tc -> ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # one to one mapping
        self.test_case_name = "one to one tc -> ppg mapping"
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]

        self.test_mapping[0] = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def sameTcToPpgMapOnDifferentIngressPortsIP(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for same tc -> ppg map on different ingress ports

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # same tc -> ppg on different ingress ports
        self.test_case_name = ("same tc -> ppg map on different" +
                               "ingress ports")
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [7, 7, 0, 4, 2, 1, 6, 3]
        tc_pg_list[1] = tc_pg_list[0]
        tc_pg_list[2] = tc_pg_list[0]
        tc_pg_list[3] = tc_pg_list[0]

        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[0]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                0]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def sameTcToPpgMapOnDifferentIngressPortsEth(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for same tc -> ppg map on different ingress ports

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # same tc -> ppg on different ingress ports
        self.test_case_name = ("same tc -> ppg map on different" +
                               "ingress ports")
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [7, 7, 0, 4, 2, 1, 6, 3]
        tc_pg_list[1] = tc_pg_list[0]
        tc_pg_list[2] = tc_pg_list[0]
        tc_pg_list[3] = tc_pg_list[0]

        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]

        for ingress_port in range(0, len(self.test_dev_ports)):
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[0]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                0]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def variousTcToPpgMappingOnDifferentIngressPortsIP(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for various tc -> ppg mapping on different ingress ports test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # different tc -> ppg on different ingress ports
        self.test_case_name = ("various tc -> ppg mapping on different " +
                               "ingress ports")

        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        # below mapping is not supported on model
        tc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[1] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[2] = [2, 1, 4, 3, 2, 6, 4, 0]
        tc_pg_list[3] = [3, 1, 7, 3, 5, 4, 2, 6]

        # below mapping works on model
        tc_pg_list[0] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[1] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[2] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[3] = [1, 1, 7, 6, 3, 4, 2, 7]

        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]
        for ingress_port in range(0, len(self.test_dev_ports)):
            mapping = combine_ingress_pfc_tc_to_pg_mapping(
                pfc_list, pfc_pg_list, tc_pg_list[ingress_port])
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[ingress_port]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                ingress_port]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def variousTcToPpgMappingOnDifferentIngressPortsEth(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for various tc -> ppg mapping on different ingress ports test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        qos_map_type = SAI_QOS_MAP_TYPE_DOT1P_TO_TC
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4
        # different tc -> ppg on different ingress ports
        self.test_case_name = ("various tc -> ppg mapping on different " +
                               "ingress ports")

        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        # below mapping is not supported on model
        tc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[1] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[2] = [2, 1, 4, 3, 2, 6, 4, 0]
        tc_pg_list[3] = [3, 1, 7, 3, 5, 4, 2, 6]

        # below mapping works on model
        tc_pg_list[0] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[1] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[2] = [1, 1, 7, 6, 3, 4, 2, 7]
        tc_pg_list[3] = [1, 1, 7, 6, 3, 4, 2, 7]

        self.test_dev_ports = [self.dev_port0, self.dev_port1,
                               self.dev_port2, self.dev_port3]
        for ingress_port in range(0, len(self.test_dev_ports)):
            mapping = combine_ingress_pfc_tc_to_pg_mapping(
                pfc_list, pfc_pg_list, tc_pg_list[ingress_port])
            self.test_mapping[ingress_port] = mapping
            self.test_pfc_to_pg_map_id[
                ingress_port] = self.pfc_to_pg_map_id[ingress_port]
            self.test_tc_to_pg_map_id[ingress_port] = self.tc_to_pg_map_id[
                ingress_port]
        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.
                test_pfc_to_pg_map_id[p])
            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                pkts = 1 + port
                expected_cnt[port][ppg] += pkts
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")

    def noPfcToPpgMappingIP(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for no pfc -> ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4

        # no pfc_ppg mapping defined
        self.test_case_name = "no pfc -> ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 0, 0, 0, 0, 0, 0, 0]  # no pfc to ppg updated
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_mapping[0] = mapping
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                print(key, ppg)
                ingress_ip_tos = key << 2
                pkts = 1 + port
                self.ipv4_pkt[IP].tos = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv4_pkt, pkts)
        self.dataplane.flush()
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")
        send_packet(self, self.dev_port3, self.ipv4_pkt)
        verify_packet(self, self.exp_ipv4_pkt, self.dev_port1)
        self.dataplane.flush()

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                ingress_ip_tos = key << 2
                pkts = 1 + port
                self.ipv6_pkt.tc = ingress_ip_tos
                send_packet(self, ingress_port, self.ipv6_pkt, pkts)
        self.dataplane.flush()
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")
        send_packet(self, self.dev_port3, self.ipv6_pkt)
        verify_packet(self, self.exp_ipv6_pkt, self.dev_port2)
        self.dataplane.flush()

    def noPfcToPpgMappingEth(
            self,
            qos_map_type=SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP):
        ''' Function configures the TC to Priority Group test data
            for no pfc -> ppg mapping test case

        Args:
            qos_map_type (uint): qos map type test variant
        '''
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.test_dev_ports = [self.dev_port0]
        self.test_pfc_to_pg_map_id = [0] * 4
        self.test_tc_to_pg_map_id = [0] * 4
        self.test_mapping = [0] * 4
        tc_pg_list = [0] * 4

        # no pfc_ppg mapping defined
        self.test_case_name = "no pfc -> ppg mapping"
        pfc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        pfc_pg_list = [0, 0, 0, 0, 0, 0, 0, 0]  # no pfc to ppg updated
        tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        tc_pg_list[0] = [0, 1, 2, 3, 4, 5, 6, 7]
        mapping = combine_ingress_pfc_tc_to_pg_mapping(
            pfc_list, pfc_pg_list, tc_pg_list[0])
        self.test_mapping[0] = mapping
        self.test_pfc_to_pg_map_id[0] = self.pfc_to_pg_map_id[0]
        self.test_tc_to_pg_map_id[0] = self.tc_to_pg_map_id[0]

        qos_map_dict = {
            "qos_pfc_priority_to_priority_group_map": 0,
            "qos_dot1p_to_tc_map": 0,
            "qos_tc_to_priority_group_map": 0,
            "qos_dscp_to_tc_map": 0}

        for port in self.test_ports:
            self.setPortMultipleQosMapIds(
                port,
                qos_map_dict)

        for ingress_port in range(0, len(self.test_dev_ports)):
            pfc_to_pg_map_id = self.test_pfc_to_pg_map_id[ingress_port]
            tc_to_pg_map_id = self.test_tc_to_pg_map_id[ingress_port]
            if (pfc_to_pg_map_id == 0) or (tc_to_pg_map_id == 0):
                continue
            # update QOS MAP PFC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, pfc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP, pfc_list,
                    pfc_pg_list), True,
                "Failed verify updated qos_map attribute")
            # update QOS MAP TC TO PRIORITY GROUP
            self.assertEqual(
                update_and_verify_qos_map(
                    self.client, tc_to_pg_map_id,
                    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                    tc_list, tc_pg_list[ingress_port]), True,
                "Failed verify updated qos_map attribute")
        p = 0
        for port in self.test_ports:
            if self.test_pfc_to_pg_map_id[p] == 0:
                # this should not happen as we created qos map for all ports
                # under test
                continue
            if qos_map_type == SAI_QOS_MAP_TYPE_DOT1P_TO_TC:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dot1p_to_tc_map=self.dot1_to_tc_map_id)
            else:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)

            # set the QOS PFC TO PRIORITY GROUP mapping
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.test_tc_to_pg_map_id[p])

            p += 1

        # get the initial counters
        expected_cnt = self.getPortPPGStats(self.test_dev_ports)
        for port in range(0, len(self.test_dev_ports)):
            ingress_port = self.test_dev_ports[port]
            for key, ppg in self.test_mapping[port]:
                print(key, ppg)
                pkts = 1 + port
                self.eth_pkt[Ether][Dot1Q].prio = key
                send_packet(self, ingress_port, self.eth_pkt, pkts)
        self.dataplane.flush()
        print("Verify port/ppg pktcounters")
        time.sleep(8)
        post_cnt = self.getPortPPGStats(self.test_dev_ports)
        self.assertEqual(
            self.comparePortPPGStats(expected_cnt, post_cnt), True)
        print("\tok")
        self.dataplane.flush()

    def runTest(self):
        try:
            # TC to Priority Group tests
            # Test case 1
            self.defaultNoTcToPpgMappingIP()
            self.defaultNoTcToPpgMappingEth()

            # Test case 2
            self.multipleTcToSamePpgMappingIP()
            self.multipleTcToSamePpgMappingEth()

            # Test case 3
            self.oneToOneTcToPpgMappingIP()
            self.oneToOneTcToPpgMappingEth()

            # Test case 4
            self.sameTcToPpgMapOnDifferentIngressPortsIP()
            self.sameTcToPpgMapOnDifferentIngressPortsEth()

            # Test case 5
            self.variousTcToPpgMappingOnDifferentIngressPortsIP()
            self.variousTcToPpgMappingOnDifferentIngressPortsEth()

            # Test case 6
            self.noPfcToPpgMappingIP()
            self.noPfcToPpgMappingEth()

        finally:
            pass


class QosTcAndColorToDscpTest(L3QosMapBaseClass):
    ''' QOS TC and COLOR to DSCP test '''

    def setUp(self):
        L3QosMapBaseClass.setUp(self)

        # setup dscp to tc and color mapping
        ingress_dscp_list = []
        p0_ingress_tc_list = []
        p1_ingress_tc_list = []
        p2_ingress_tc_list = []
        p3_ingress_tc_list = []
        for dscp in range(0, 64):
            ingress_dscp_list.append(dscp)
            # ingress_tc_list.append(5)
            if dscp < 24:
                p0_tc = dscp % 8
                p1_tc = (dscp + 1) % 8
                p2_tc = (dscp + 2) % 8
                p3_tc = (dscp + 3) % 8
            else:
                p0_tc = int(dscp / 8)
                p1_tc = int((dscp + 1) / 8) % 8
                p2_tc = int((dscp + 2) / 8) % 8
                p3_tc = int((dscp + 3) / 8) % 8

            p0_ingress_tc_list.append(p0_tc)
            p1_ingress_tc_list.append(p1_tc)
            p2_ingress_tc_list.append(p2_tc)
            p3_ingress_tc_list.append(p3_tc)

        # define ingress DSCP -> TC per port
        self.p0_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
            p0_ingress_tc_list)
        self.assertTrue(self.p0_qos_dscp_to_tc_map_id != 0,
                        "Failed to create qos_map")
        self.p1_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
            p1_ingress_tc_list)
        self.assertTrue(self.p1_qos_dscp_to_tc_map_id != 0,
                        "Failed to create qos_map")
        self.p2_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
            p2_ingress_tc_list)
        self.assertTrue(self.p2_qos_dscp_to_tc_map_id != 0,
                        "Failed to create qos_map")
        self.p3_qos_dscp_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
            p3_ingress_tc_list)
        self.assertTrue(self.p3_qos_dscp_to_tc_map_id != 0,
                        "Failed to create qos_map")

        # ingress settings
        # set Port 0 DSCP -> TC mapping
        # Ports 1, 2, 3 will be assigned in tests
        for port in [self.port0]:
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_dscp_to_tc_map=self.p0_qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            attr = sai_thrift_get_port_attribute(self.client,
                                                 port,
                                                 qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                             self.p0_qos_dscp_to_tc_map_id)

        # an example egress tc and color -> dscp
        # egress dscp = color * tc
        # defines mapping for egress dscp from 0 to 23
        egress_tc_color_list = [
            [0, 0],
            [1, 0],
            [2, 0],
            [3, 0],
            [4, 0],
            [5, 0],
            [6, 0],
            [7, 0],  # green
            [0, 1],
            [1, 1],
            [2, 1],
            [3, 1],
            [4, 1],
            [5, 1],
            [6, 1],
            [7, 1],  # yellow
            [0, 2],
            [1, 2],
            [2, 2],
            [3, 2],
            [4, 2],
            [5, 2],
            [6, 2],
            [7, 2],  # red
        ]
        egress_dscp_list = [
            0, 1, 2, 3, 4, 5, 6, 7,  # mapping green
            8, 9, 10, 11, 12, 13, 14, 15,  # mapping yellow
            16, 17, 18, 19, 20, 21, 22, 23  # mapping red
        ]
        self.qos_tc_color_to_dscp_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
            egress_tc_color_list, egress_dscp_list)
        self.assertTrue(self.qos_tc_color_to_dscp_map_id != 0,
                        "Failed to create qos_map")

    def l3IPv4QosMapTcColorToDscpDefaultMappingTest(self):
        ''' L3 IPv4 no TC + Color -> DSCP mapping defined (Default Case)
            Test verifies that switch does not override the
            original packet dscp value '''

        print("l3IPv4QosMapTcColorToDscpDefaultMappingTest")
        try:
            for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                ingress_ip_tos = ingress_dscp << 2
                egress_ip_tos = ingress_ip_tos
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ingress_ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=egress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)

                # print("Sending IPv4 packet port %d (dscp=%d ip_tos=%d) ->"
                #       " port %d (ip_tos=%d)"
                #       % (self.dev_port0, ingress_dscp, ingress_ip_tos,
                #          self.dev_port1, egress_ip_tos))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port1)
                # print("\tok")

        finally:
            pass

    def l3IPv6QosMapTcColorToDscpDefaultMappingTest(self):
        ''' L3 IPv6 no TC + Color -> DSCP mapping defined (Default Case)
            Test verifies that switch does not override the
            original packet dscp value '''

        print("l3IPv6QosMapTcColorToDscpDefaultMappingTest")
        try:
            for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                egress_dscp = ingress_dscp
                ingress_ipv6_tc = ingress_dscp << 2
                egress_ipv6_tc = egress_dscp << 2
                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ingress_ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=egress_ipv6_tc,
                    pktlen=100)

                # print("Sending IPv6 packet port %d (dscp=%d) ->"
                #       " port %d (egress_dscp=%s)"
                #       % (self.dev_port0, ingress_dscp, self.dev_port2,
                #          egress_dscp))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                # print("\tok")

        finally:
            pass

    def l3IPv4QosMapTcColorToDscpMappingTest(self):
        ''' L3 IPv4
            TC + Color -> DSCP mapping defined
            Test verifies that switch does override the
            original packet dscp value accordingly to QOS mapping'''

        print("l3IPv4QosMapTcColorToDscpMappingTest")
        try:
            # egress settings
            # set the TC AND COLOR -> DSCP mapping
            # for port 1 for IPv4 and port2 for IPv6
            for port in [self.port1]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.
                    qos_tc_color_to_dscp_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                                 self.qos_tc_color_to_dscp_map_id)

            for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                if ingress_dscp < 24:
                    egress_dscp = ingress_dscp % 8
                else:
                    egress_dscp = int(ingress_dscp / 8)

                ingress_ip_tos = ingress_dscp << 2
                egress_ip_tos = egress_dscp << 2
                pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                        eth_src='00:22:22:22:22:22',
                                        ip_dst='10.10.10.11',
                                        ip_src='192.168.0.1',
                                        ip_tos=ingress_ip_tos,
                                        ip_id=105,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                            eth_src=ROUTER_MAC,
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=egress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=63)
                # print("Sending IPv4 packet port %d (dscp=%d ip_tos=%d) ->"
                #       " port %d (ip_tos=%d)"
                #       % (self.dev_port0, ingress_dscp, ingress_ip_tos,
                #          self.dev_port1, egress_ip_tos))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port1)
                # print("\tok")

        finally:
            all_ports = [self.port0, self.port1, self.port2, self.port3]
            for port in all_ports:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_and_color_to_dscp_map=0)

    def l3IPv6QosMapTcColorToDscpMappingTest(self):
        ''' L3 IPv6
            TC + Color -> DSCP mapping defined
            Test verifies that switch does override the
            original packet dscp value accordingly to QOS mapping'''

        print("l3IPv6QosMapTcColorToDscpMappingTest")
        try:
            # egress settings
            # set the TC AND COLOR -> DSCP mapping
            # for port 1 for IPv4 and port2 for IPv6
            for port in [self.port2]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.
                    qos_tc_color_to_dscp_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                                 self.qos_tc_color_to_dscp_map_id)

            for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                if ingress_dscp < 24:
                    egress_dscp = ingress_dscp % 8
                else:
                    egress_dscp = int(ingress_dscp / 8)

                ingress_ipv6_tc = ingress_dscp << 2
                egress_ipv6_tc = egress_dscp << 2

                pkt = simple_tcpv6_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=64,
                    ipv6_tc=ingress_ipv6_tc,
                    pktlen=100)
                exp_pkt = simple_tcpv6_packet(
                    eth_dst='00:11:22:33:44:06',
                    eth_src=ROUTER_MAC,
                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                    ipv6_src='2000::1',
                    ipv6_hlim=63,
                    ipv6_tc=egress_ipv6_tc,
                    pktlen=100)

                # print("Sending IPv6 packet port %d (dscp=%d) ->"
                #       " port %d (egress_dscp=%s)"
                #       % (self.dev_port0, ingress_dscp, self.dev_port2,
                #          egress_dscp))
                send_packet(self, self.dev_port0, pkt)
                verify_packet(self, exp_pkt, self.dev_port2)
                # print("\tok")

        finally:
            for port in [self.port1, self.port2]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=0)

    def l3IPv4QosMapTcColorToDscpManyIngressPortsTest(self):
        ''' L3 IPv4
            TC + Color -> DSCP same mapping defined on various egress ports
            Test verifies that switch does override the
            original packet dscp value accordingly to QOS mapping.
        '''

        print("l3IPv4QosMapTcColorToDscpManyIngressPortsTest")
        try:
            # egress settings
            # set the TC AND COLOR -> DSCP mapping
            # for port 1 for IPv4 and port2 for IPv6
            # INFO setting both ingress TC and COLOR unsupported
            for port, dscp_to_tc in [
                    [self.port0, self.p0_qos_dscp_to_tc_map_id],
                    [self.port2, self.p0_qos_dscp_to_tc_map_id],
                    [self.port3, self.p0_qos_dscp_to_tc_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=dscp_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'], dscp_to_tc)

            for port in [self.port1]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.
                    qos_tc_color_to_dscp_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                                 self.qos_tc_color_to_dscp_map_id)

            for port in [self.dev_port0, self.dev_port2, self.dev_port3]:
                for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                    if ingress_dscp < 24:
                        egress_dscp = ingress_dscp % 8
                    else:
                        egress_dscp = int(ingress_dscp / 8)

                    ingress_ip_tos = ingress_dscp << 2
                    egress_ip_tos = egress_dscp << 2
                    pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                            eth_src='00:22:22:22:22:22',
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ingress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=64)
                    exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                                eth_src=ROUTER_MAC,
                                                ip_dst='10.10.10.11',
                                                ip_src='192.168.0.1',
                                                ip_tos=egress_ip_tos,
                                                ip_id=105,
                                                ip_ttl=63)
                    # print("Sending IPv4 packet port %d (dscp=%d ip_tos=%d)->"
                    #       " port %d (ip_tos=%d)"
                    #       % (port, ingress_dscp, ingress_ip_tos,
                    #          self.dev_port1, egress_ip_tos))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, self.dev_port1)
                    # print("\tok")

        finally:
            all_ports = [self.port0, self.port1, self.port2, self.port3]
            for port in all_ports:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dscp_to_tc_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_and_color_to_dscp_map=0)

    def l3IPv6QosMapTcColorToDscpManyIngressPortsTest(self):
        ''' L3 IPv6
            TC + Color -> DSCP same mapping defined on various ingress ports
            Test verifies that switch does override the
            original packet dscp value accordingly to QOS mapping.
        '''

        print("l3IPv6QosMapTcColorToDscpManyIngressPortsTest")
        try:
            # set ingress DSCP -> tc
            for port, dscp_to_tc in [
                    [self.port0, self.p0_qos_dscp_to_tc_map_id],
                    [self.port1, self.p0_qos_dscp_to_tc_map_id],
                    [self.port3, self.p0_qos_dscp_to_tc_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=dscp_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'], dscp_to_tc)

            # egress settings
            # set the TC AND COLOR -> DSCP mapping
            # for port 1 for IPv4 and port2 for IPv6
            for port in [self.port2]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.
                    qos_tc_color_to_dscp_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                                 self.qos_tc_color_to_dscp_map_id)

            for port in [self.dev_port0, self.dev_port1, self.dev_port3]:
                for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                    if ingress_dscp < 24:
                        egress_dscp = ingress_dscp % 8
                    else:
                        egress_dscp = int(ingress_dscp / 8)

                    ingress_ipv6_tc = ingress_dscp << 2
                    egress_ipv6_tc = egress_dscp << 2

                    pkt = simple_tcpv6_packet(
                        eth_dst=ROUTER_MAC,
                        eth_src='00:22:22:22:22:22',
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=64,
                        ipv6_tc=ingress_ipv6_tc,
                        pktlen=100)
                    exp_pkt = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:06',
                        eth_src=ROUTER_MAC,
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=63,
                        ipv6_tc=egress_ipv6_tc,
                        pktlen=100)

                    # print("Sending IPv6 packet port %d (dscp=%d) -> "
                    #       " port %d (egress_dscp=%s)"
                    #      % (port, ingress_dscp, self.dev_port2, egress_dscp))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, self.dev_port2)
                    # print("\tok")

        finally:
            for port in [self.port1, self.port2]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=0)

    def l3IPv4QosMapVariousTcColorToDscpManyIngressPortsTest(self):
        ''' L3 IPv4
            TC + Color -> DSCP various mapping defined on various ingress ports
            Test verifies that switch does override the
            original packet dscp value accordingly to QOS mapping.
        '''

        print("l3IPv4QosMapVariousTcColorToDscpManyIngressPortsTest")
        try:
            # egress settings
            # set the TC AND COLOR -> DSCP mapping
            # for port 1 for IPv4 and port2 for IPv6
            for port, dscp_to_tc in [
                    [self.port0, self.p0_qos_dscp_to_tc_map_id],
                    [self.port2, self.p2_qos_dscp_to_tc_map_id],
                    [self.port3, self.p3_qos_dscp_to_tc_map_id]]:

                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=dscp_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'], dscp_to_tc)

            for port in [self.port1]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.
                    qos_tc_color_to_dscp_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                                 self.qos_tc_color_to_dscp_map_id)
            test_dev_port_list = [self.dev_port0, self.dev_port1,
                                  self.dev_port2, self.dev_port3]
            for p_idx, port in enumerate(test_dev_port_list):
                if port == self.dev_port1:
                    continue
                for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                    if ingress_dscp < 24:
                        egress_dscp = (ingress_dscp + p_idx) % 8
                    else:
                        egress_dscp = int((ingress_dscp + p_idx) / 8) % 8

                    ingress_ip_tos = ingress_dscp << 2
                    egress_ip_tos = egress_dscp << 2
                    pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                            eth_src='00:22:22:22:22:22',
                                            ip_dst='10.10.10.11',
                                            ip_src='192.168.0.1',
                                            ip_tos=ingress_ip_tos,
                                            ip_id=105,
                                            ip_ttl=64)
                    exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:04',
                                                eth_src=ROUTER_MAC,
                                                ip_dst='10.10.10.11',
                                                ip_src='192.168.0.1',
                                                ip_tos=egress_ip_tos,
                                                ip_id=105,
                                                ip_ttl=63)
                    # print("Sending IPv4 packet port %d (dscp=%d ip_tos=%d)->"
                    #       "port %d (dscp=%d ip_tos=%d)"
                    #       % (port, ingress_dscp, ingress_ip_tos,
                    #          self.dev_port1, egress_dscp, egress_ip_tos))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, self.dev_port1)
                    # print("\tok")

        finally:
            all_ports = [self.port0, self.port1, self.port2, self.port3]
            for port in all_ports:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dscp_to_tc_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_and_color_to_dscp_map=0)

    def l3IPv6QosMapVariousTcColorToDscpManyIngressPortsTest(self):
        ''' L3 IPv6
            TC + Color -> DSCP various mapping defined on various ingress ports
            Test verifies that switch does override the
            original packet dscp value accordingly to QOS mapping.
        '''

        print("l3IPv6QosMapVariousTcColorToDscpManyIngressPortsTest")
        try:
            # set ingress DSCP -> tc
            for port, dscp_to_tc in [
                    [self.port0, self.p0_qos_dscp_to_tc_map_id],
                    [self.port1, self.p1_qos_dscp_to_tc_map_id],
                    [self.port3, self.p3_qos_dscp_to_tc_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dscp_to_tc_map=dscp_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'], dscp_to_tc)

            # egress settings
            # set the TC AND COLOR -> DSCP mapping
            # for port 1 for IPv4 and port2 for IPv6
            for port in [self.port2]:
                # set Port 1 TC AND COLOR -> DSCP mapping
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.
                    qos_tc_color_to_dscp_map_id)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dscp_map'],
                                 self.qos_tc_color_to_dscp_map_id)

            test_dev_port_list = [self.dev_port0, self.dev_port1,
                                  self.dev_port2, self.dev_port3]
            for p_idx, port in enumerate(test_dev_port_list):
                if port == self.dev_port2:
                    continue
                for ingress_dscp in range(0, 64, DSCP_TEST_STEP):
                    if ingress_dscp < 24:
                        egress_dscp = (ingress_dscp + p_idx) % 8
                    else:
                        egress_dscp = int((ingress_dscp + p_idx) / 8) % 8

                    ingress_ipv6_tc = ingress_dscp << 2
                    egress_ipv6_tc = egress_dscp << 2

                    pkt = simple_tcpv6_packet(
                        eth_dst=ROUTER_MAC,
                        eth_src='00:22:22:22:22:22',
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=64,
                        ipv6_tc=ingress_ipv6_tc,
                        pktlen=100)
                    exp_pkt = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:06',
                        eth_src=ROUTER_MAC,
                        ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:1111',
                        ipv6_src='2000::1',
                        ipv6_hlim=63,
                        ipv6_tc=egress_ipv6_tc,
                        pktlen=100)

                    # print("Sending IPv6 packet port %d (dscp=%d) -> "
                    #       " port %d (dscp=%s)"
                    #      % (port, ingress_dscp, self.dev_port2, egress_dscp))
                    send_packet(self, port, pkt)
                    verify_packet(self, exp_pkt, self.dev_port2)
                    # print("\tok")

        finally:
            all_ports = [self.port0, self.port1, self.port2, self.port3]
            for port in all_ports:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dscp_to_tc_map=0)
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_and_color_to_dscp_map=0)

    def runTest(self):
        try:
            self.l3IPv4QosMapTcColorToDscpDefaultMappingTest()
            self.l3IPv6QosMapTcColorToDscpDefaultMappingTest()
            self.l3IPv4QosMapTcColorToDscpMappingTest()
            self.l3IPv6QosMapTcColorToDscpMappingTest()
            self.l3IPv4QosMapTcColorToDscpManyIngressPortsTest()
            self.l3IPv6QosMapTcColorToDscpManyIngressPortsTest()
            self.l3IPv4QosMapVariousTcColorToDscpManyIngressPortsTest()
            self.l3IPv6QosMapVariousTcColorToDscpManyIngressPortsTest()

        finally:
            pass

    def tearDown(self):
        for port in [self.port0, self.port1, self.port2, self.port3]:
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_dscp_to_tc_map=0)
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_tc_and_color_to_dscp_map=0)

        sai_thrift_remove_qos_map(self.client,
                                  self.qos_tc_color_to_dscp_map_id)
        sai_thrift_remove_qos_map(self.client, self.p0_qos_dscp_to_tc_map_id)
        sai_thrift_remove_qos_map(self.client, self.p1_qos_dscp_to_tc_map_id)
        sai_thrift_remove_qos_map(self.client, self.p2_qos_dscp_to_tc_map_id)
        sai_thrift_remove_qos_map(self.client, self.p3_qos_dscp_to_tc_map_id)

        L3QosMapBaseClass.tearDown(self)


class L2QosMapPcpToColorTest(L2QosMapBaseClass):
    ''' L2 PCP -> COLOR QOS mapping test base class '''

    def setUp(self):

        L2QosMapBaseClass.setUp(self)

        print("Create dot1p -> tc qos mapping")
        ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_dot1p_list,
            ingress_tc_list)
        self.assertTrue(self.qos_dot1p_to_tc_map_id != 0,
                        "Failed to create qos_map")

        print("Create dot1p -> color qos mapping")
        ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_color_list = [0, 0, 0, 1, 1, 1, 2, 2]
        # ingress_color_list = [1, 1, 1, 1, 1, 1, 1, 1]
        self.qos_dot1p_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR, ingress_dot1p_list,
            ingress_color_list)
        self.assertTrue(self.qos_dot1p_to_color_map_id != 0,
                        "Failed to create qos_map")

        # Used by l2QosMapDifferentPCPToColorMultiIngresssPortTest
        # QOS map defined for individual ports
        ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_color_list = [0, 0, 0, 0, 0, 0, 0, 0]
        self.p1_qos_dot1p_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR, ingress_dot1p_list,
            ingress_color_list)
        self.assertTrue(self.p1_qos_dot1p_to_color_map_id != 0,
                        "Failed to create qos_map")
        ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_color_list = [1, 1, 1, 1, 1, 1, 1, 1]
        self.p2_qos_dot1p_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR, ingress_dot1p_list,
            ingress_color_list)
        self.assertTrue(self.p2_qos_dot1p_to_color_map_id != 0,
                        "Failed to create qos_map")
        ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_color_list = [2, 2, 2, 2, 2, 2, 2, 2]
        self.p3_qos_dot1p_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR, ingress_dot1p_list,
            ingress_color_list)
        self.assertTrue(self.p3_qos_dot1p_to_color_map_id != 0,
                        "Failed to create qos_map")

        # define egress tc, color -> pcp settings
        egress_tc_color_list = [
            [0, 0],
            [1, 0],
            [2, 0],
            [3, 0],
            [4, 0],
            [5, 0],
            [6, 0],
            [7, 0],  # tc and green
            [0, 1],
            [1, 1],
            [2, 1],
            [3, 1],
            [4, 1],
            [5, 1],
            [6, 1],
            [7, 1],  # tc and yellow
            [0, 2],
            [1, 2],
            [2, 2],
            [3, 2],
            [4, 2],
            [5, 2],
            [6, 2],
            [7, 2]
        ]  # tc and red
        egress_pcp_list = [
            1, 1, 1, 1, 1, 1, 1, 1,  # p1 egress pcp for green
            2, 2, 2, 2, 2, 2, 2, 2,  # p1 egress pcp for yellow
            3, 3, 3, 3, 3, 3, 3, 3,  # p1 egress pcp for red
        ]
        self.p1_qos_tc_color_to_dot1q_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
            egress_tc_color_list, egress_pcp_list)
        self.assertTrue(self.p1_qos_tc_color_to_dot1q_id != 0,
                        "Failed to create qos_map")
        egress_pcp_list = [
            3, 3, 3, 3, 3, 3, 3, 3,  # p2 egress pcp for green
            4, 4, 4, 4, 4, 4, 4, 4,  # p2 egress pcp for yellow
            5, 5, 5, 5, 5, 5, 5, 5,  # p2 egress pcp for red
        ]
        self.p2_qos_tc_color_to_dot1q_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
            egress_tc_color_list, egress_pcp_list)
        self.assertTrue(self.p2_qos_tc_color_to_dot1q_id != 0,
                        "Failed to create qos_map")
        egress_pcp_list = [
            5, 5, 5, 5, 5, 5, 5, 5,  # p3 egress pcp for green
            6, 6, 6, 6, 6, 6, 6, 6,  # p3 egress pcp for yellow
            7, 7, 7, 7, 7, 7, 7, 7,  # p3 egress pcp for red
        ]
        self.p3_qos_tc_color_to_dot1q_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
            egress_tc_color_list, egress_pcp_list)
        self.assertTrue(self.p3_qos_tc_color_to_dot1q_id != 0,
                        "Failed to create qos_map")

    def tearDown(self):
        for port in [self.port0, self.port1, self.port2, self.port3]:
            sai_thrift_set_port_attribute(self.client, port, qos_default_tc=0)
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_tc_to_queue_map=0)
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_tc_and_color_to_dot1p_map=0)
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_dot1p_to_color_map=0)
            sai_thrift_set_port_attribute(self.client,
                                          port,
                                          qos_dot1p_to_tc_map=0)

        sai_thrift_remove_qos_map(self.client, self.qos_dot1p_to_tc_map_id)
        sai_thrift_remove_qos_map(self.client, self.qos_dot1p_to_color_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p1_qos_tc_color_to_dot1q_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p2_qos_tc_color_to_dot1q_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p3_qos_tc_color_to_dot1q_id)

        sai_thrift_remove_qos_map(self.client,
                                  self.p1_qos_dot1p_to_color_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p2_qos_dot1p_to_color_map_id)
        sai_thrift_remove_qos_map(self.client,
                                  self.p3_qos_dot1p_to_color_map_id)

        L2QosMapBaseClass.tearDown(self)

    def l2QosMapMultiPCPToOneColorMappingTest(self):
        ''' L2 traffic test verifies the following:
            1. Many PCP to one color mapping
            The verification method:
                - SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR mapping defined for ingress
                and assigned to ports 0, 1, 2, and 3
                - SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P mapping defined
                for ingress and assigned to ports 0, 1, 2, and 3
                - various SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P mappings
                defined for egress and assigned to ports 0, 1, 2, and 3
                egress pcp = 2 x egress port - 1 + color
        '''

        print("l2QosMapMultiPCPToOneColorMappingTest")
        # default PCP to TC mapping
        test_cases = []
        # priority vlan tagged packed
        test_cases.append({
            'pcp': None,
            'port_default_tc': 0,
            'tc': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 1,
            'tc': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 2,
            'tc': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 3,
            'tc': 3,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 4,
            'tc': 4,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 5,
            'tc': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 6,
            'tc': 6,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 7,
            'tc': 7,
            'color': 0
        })

        #
        test_cases.append({
            'pcp': 0,
            'port_default_tc': 5,
            'tc': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 5,
            'tc': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 0,
            'tc': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 0,
            'tc': 3,
            'color': 1
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 0,
            'tc': 4,
            'color': 1
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 0,
            'tc': 5,
            'color': 1
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 0,
            'tc': 6,
            'color': 2
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'tc': 7,
            'color': 2
        })

        try:
            # assign to port the tc_queue and tc_color_to_pcp qos map
            for port, dot1p_to_tc, dot1p_color, tc_color in [
                    [self.port0, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port1, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port2, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p2_qos_tc_color_to_dot1q_id],
                    [self.port3, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p3_qos_tc_color_to_dot1q_id]]:
                # set DOT1P -> TC
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)
                # set DOT1P -> COLOR
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_color_map=dot1p_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dot1p_to_color_map=True)
                self.assertEqual(attr['qos_dot1p_to_color_map'], dot1p_color)
                # set TC and COLOR -> DOT1Q
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=tc_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dot1p_map'],
                                 tc_color)

            for test in test_cases:
                if test['pcp'] is not None:
                    vlan = 1
                    ingress_pcp = str(test['pcp'])
                else:
                    vlan = 0
                    ingress_pcp = 'None'
                # define expected egress_pcp per egress port
                egress_tc = test['tc']
                egress_color = test['color']
                p1_egress_pcp = 1 + test['color']
                p2_egress_pcp = 3 + test['color']
                p3_egress_pcp = 5 + test['color']

                print("Sending eth packet port %d (pcp=%s) ->"
                      " port %d (tc=%d color=%d -> egress_pcp=%d)"
                      % (self.dev_port0, ingress_pcp,
                         self.dev_port1, egress_tc, egress_color,
                         p1_egress_pcp))
                print("%47s port %d (tc=%d color=%d -> egress_pcp=%d))" %
                      (" ", self.dev_port2, egress_tc, egress_color,
                       p2_egress_pcp))
                print("%47s port %d (tc=%d color=%d -> egress_pcp=%d))" %
                      (" ", self.dev_port3, egress_tc, egress_color,
                       p3_egress_pcp))

                pkt = simple_tcp_packet(eth_dst='00:33:33:33:33:00',
                                        eth_src='00:33:33:33:33:11',
                                        dl_vlan_enable=True,
                                        vlan_vid=vlan,
                                        vlan_pcp=test['pcp'],
                                        pktlen=104)
                p1_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p1_egress_pcp,  # port1 tc_color-> dot1q mapping
                    pktlen=104)
                p2_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p2_egress_pcp,  # port2 tc_color-> dot1q mapping
                    pktlen=104)
                p3_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p3_egress_pcp,  # port3 tc_color-> dot1q mapping
                    pktlen=104)

                test_port = self.dev_port0
                flood_port_list = [[self.dev_port1], [self.dev_port2],
                                   [self.dev_port3]]
                flood_pkt_list = [p1_exp_pkt, p2_exp_pkt, p3_exp_pkt]

                send_packet(self, test_port, pkt)
                verify_each_packet_on_multiple_port_lists(self, flood_pkt_list,
                                                          flood_port_list)
                print("\tPacket flooded. ok")

        finally:
            pass

    def l2QosMapPCPToColorDefaultMappingTest(self):
        ''' L2 traffic test verifies the following:
            1. default PCP to color mapping
            The verification method:
            No SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR mapping defined
            Mapping the tc and color to pcp on egress port.
            All colors map to pcp=0, only default color GREEN
            maps to pcp 7,
        '''
        print("l2QosMapPCPToColorDefaultMappingTest")

        # default PCP to TC mapping
        test_cases = []
        # priority vlan tagged packed
        test_cases.append({
            'pcp': None,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 1,
            'queue': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 2,
            'queue': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 3,
            'queue': 3,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 4,
            'queue': 4,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 5,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 6,
            'queue': 6,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 7,
            'queue': 7,
            'color': 0
        })

        #
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 5,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 0,
            'port_default_tc': 1,
            'queue': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 2,
            'queue': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 3,
            'queue': 3,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 4,
            'queue': 4,
            'color': 0
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 5,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 6,
            'queue': 6,
            'color': 0
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 7,
            'queue': 7,
            'color': 0
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })

        try:
            # setup tc to queue index mapping
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")
            # assign to port the tc_queue and tc_color_to_pcp qos map
            for port, tc_to_queue, tc_color in [
                    [self.port0, qos_tc_to_queue_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port1, qos_tc_to_queue_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port2, qos_tc_to_queue_map_id,
                     self.p2_qos_tc_color_to_dot1q_id],
                    [self.port3, qos_tc_to_queue_map_id,
                     self.p3_qos_tc_color_to_dot1q_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=tc_to_queue)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'], tc_to_queue)
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=tc_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dot1p_map'],
                                 tc_color)

            # verify port default tc
            ports = [self.port0, self.port1, self.port2, self.port3]
            self.verifyPortDefaultDot1pToTc(ports)

            for test in test_cases:
                queue = test['queue']
                # setup port default_tc
                if test['port_default_tc'] is not None:
                    # every test port gets the same default_tc =
                    # test['port_default_tc']
                    port_default_tc = test['port_default_tc']
                    port_config = [[self.port0, port_default_tc],
                                   [self.port1, port_default_tc],
                                   [self.port2, port_default_tc],
                                   [self.port3, port_default_tc]]
                else:
                    # every port gets default_tc as its port number
                    # port 0 -> default tc = 5
                    # port 1 -> default tc = 1
                    # port 2 -> default tc = 2
                    # port 3 -> default tc = 3
                    port_config = [[self.port0, 5], [self.port1, 1],
                                   [self.port2, 2], [self.port3, 3]]

                for port, port_default_tc in port_config:
                    status = sai_thrift_set_port_attribute(
                        self.client, port, qos_default_tc=port_default_tc)
                    attr = sai_thrift_get_port_attribute(self.client,
                                                         port,
                                                         qos_default_tc=True)
                    self.assertEqual(attr['qos_default_tc'], port_default_tc)
                p1_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p2_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p3_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port3, queue, ['SAI_QUEUE_STAT_PACKETS'])

                if test['port_default_tc'] is not None:
                    port_default_tc = str(test['port_default_tc'])
                else:
                    port_default_tc = str(1)
                if test['pcp'] is not None:
                    vlan = 1
                    ingress_pcp = str(test['pcp'])
                else:
                    vlan = 0
                    ingress_pcp = 'None'
                # define expected egress_pcp per egress port
                p1_egress_pcp = 1
                p2_egress_pcp = 3
                p3_egress_pcp = 5

                print("Sending packet port %d (port_default_tc=%s"
                      ", pcp=%s) -> port %d (queue=%d, egress_pcp=%d)"
                      % (self.dev_port0, port_default_tc,
                         ingress_pcp, self.dev_port1, queue, p1_egress_pcp))
                print("%54s port %d (queue=%d, egress_pcp=%d))" %
                      (" ", self.dev_port2, queue, p2_egress_pcp))
                print("%54s port %d (queue=%d, egress_pcp=%d))" %
                      (" ", self.dev_port3, queue, p3_egress_pcp))

                pkt = simple_tcp_packet(eth_dst='00:33:33:33:33:00',
                                        eth_src='00:33:33:33:33:11',
                                        dl_vlan_enable=True,
                                        vlan_vid=vlan,
                                        vlan_pcp=test['pcp'],
                                        pktlen=104)
                p1_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p1_egress_pcp,  # port1 tc_color-> dot1q mapping
                    pktlen=104)
                p2_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p2_egress_pcp,  # port2 tc_color-> dot1q mapping
                    pktlen=104)
                p3_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p3_egress_pcp,  # port3 tc_color-> dot1q mapping
                    pktlen=104)

                test_port = self.dev_port0
                flood_port_list = [[self.dev_port1], [self.dev_port2],
                                   [self.dev_port3]]
                flood_pkt_list = [p1_exp_pkt, p2_exp_pkt, p3_exp_pkt]
                # flood_pkt_list = [pkt, pkt, pkt]

                send_packet(self, test_port, pkt)
                verify_each_packet_on_multiple_port_lists(self, flood_pkt_list,
                                                          flood_port_list)
                print("\tPacket flooded. ok")

                p1_post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p2_post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p3_post_q_cnt = self.getPortQueueIndexStats(
                    self.port3, queue, ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    p1_initial_q_cnt + 1, p1_post_q_cnt,
                    'PORT1 queue {} packets counter {} != {}'.format(
                        queue, p1_initial_q_cnt + 1, p1_post_q_cnt))
                self.assertEqual(
                    p2_initial_q_cnt + 1, p2_post_q_cnt,
                    'PORT2 queue {} packets counter {} != {}'.format(
                        queue, p2_initial_q_cnt + 1, p2_post_q_cnt))
                self.assertEqual(
                    p3_initial_q_cnt + 1, p3_post_q_cnt,
                    'PORT3 queue {} packets counter {} != {}'.format(
                        queue, p3_initial_q_cnt + 1, p3_post_q_cnt))

        finally:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_to_queue_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_and_color_to_dot1p_map=0)
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)

    def verifyPortDefaultDot1pToTc(self, ports):
        """
        Verifies port default tc

        Args:
            ports (list): list of ports
        """
        for port in ports:
            attr = sai_thrift_get_port_attribute(self.client,
                                                 port,
                                                 qos_dot1p_to_tc_map=True,
                                                 qos_default_tc=True)
            self.assertEqual(attr['qos_dot1p_to_tc_map'], 0)
            self.assertEqual(attr['qos_default_tc'], 0)

    def l2QosMapSamePCPToColorMultiIngresssPortTest(self):
        ''' L2 traffic test verifies the following:
            1. Many PCP to one color mapping
            The verification method:
                - SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR mapping defined for ingress
                and assigned to ports 0, 1, 2, and 3
                - SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P mapping defined for
                ingress and assigned to ports 0, 1, 2, and 3
                - various SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P mappings
                  defined for egress and assigned to ports 0, 1, 2, and 3
                egress pcp = 2 x egress port - 1 + color
        '''
        print("l2QosMapSamePCPToColorMultiIngresssPortTest")

        # default PCP to TC mapping
        test_cases = []
        # priority vlan tagged packed
        test_cases.append({
            'pcp': None,
            'port_default_tc': 0,
            'tc': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 1,
            'tc': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 2,
            'tc': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 3,
            'tc': 3,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 4,
            'tc': 4,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 5,
            'tc': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 6,
            'tc': 6,
            'color': 0
        })
        test_cases.append({
            'pcp': None,
            'port_default_tc': 7,
            'tc': 7,
            'color': 0
        })

        test_cases.append({
            'pcp': 0,
            'port_default_tc': 5,
            'tc': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 5,
            'tc': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 0,
            'tc': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 0,
            'tc': 3,
            'color': 1
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 0,
            'tc': 4,
            'color': 1
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 0,
            'tc': 5,
            'color': 1
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 0,
            'tc': 6,
            'color': 2
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'tc': 7,
            'color': 2
        })

        try:
            for port, dot1p_to_tc, dot1p_color, tc_color in [
                    [self.port0, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port1, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port2, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p2_qos_tc_color_to_dot1q_id],
                    [self.port3, self.qos_dot1p_to_tc_map_id,
                     self.qos_dot1p_to_color_map_id,
                     self.p3_qos_tc_color_to_dot1q_id]]:
                # set DOT1P -> TC
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)
                # set DOT1P -> COLOR
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_color_map=dot1p_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dot1p_to_color_map=True)
                self.assertEqual(attr['qos_dot1p_to_color_map'], dot1p_color)
                # set TC and COLOR -> DOT1Q
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=tc_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dot1p_map'],
                                 tc_color)

            test_dev_ports_list = [self.dev_port0, self.dev_port1,
                                   self.dev_port2, self.dev_port3]
            for _, ingress_port in enumerate(test_dev_ports_list):
                for test in test_cases:
                    if test['pcp'] is not None:
                        vlan = 1
                        ingress_pcp = str(test['pcp'])
                    else:
                        vlan = 0
                        ingress_pcp = 'None'
                    # define expected egress_pcp per egress port
                    egress_tc = test['tc']
                    egress_color = test['color']
                    p1_egress_pcp = 1 + test['color']
                    p2_egress_pcp = 3 + test['color']
                    p3_egress_pcp = 5 + test['color']

                    pkt = simple_tcp_packet(eth_dst='00:33:33:33:33:00',
                                            eth_src='00:33:33:33:33:11',
                                            dl_vlan_enable=True,
                                            vlan_vid=vlan,
                                            vlan_pcp=test['pcp'],
                                            pktlen=104)
                    p1_exp_pkt = simple_tcp_packet(
                        eth_dst='00:33:33:33:33:00',
                        eth_src='00:33:33:33:33:11',
                        dl_vlan_enable=True,
                        vlan_vid=1,
                        vlan_pcp=p1_egress_pcp,
                        pktlen=104)
                    p2_exp_pkt = simple_tcp_packet(
                        eth_dst='00:33:33:33:33:00',
                        eth_src='00:33:33:33:33:11',
                        dl_vlan_enable=True,
                        vlan_vid=1,
                        vlan_pcp=p2_egress_pcp,
                        pktlen=104)
                    p3_exp_pkt = simple_tcp_packet(
                        eth_dst='00:33:33:33:33:00',
                        eth_src='00:33:33:33:33:11',
                        dl_vlan_enable=True,
                        vlan_vid=1,
                        vlan_pcp=p3_egress_pcp,
                        pktlen=104)

                    egres_ports = []
                    flood_port_list = []
                    flood_pkt_list = []

                    pkt_list = [p1_exp_pkt, p1_exp_pkt, p2_exp_pkt, p3_exp_pkt]

                    for i, port in enumerate(test_dev_ports_list):
                        if port == ingress_port:
                            continue
                        flood_port_list.append([port])
                        flood_pkt_list.append(pkt_list[i])
                        egres_ports.append(port)

                    print("Sending eth packet port %d (pcp=%s) -> "
                          "port %d (tc=%d color=%d -> egress_pcp=%d)"
                          % (ingress_port, ingress_pcp,
                             egres_ports[0], egress_tc, egress_color,
                             p1_egress_pcp))
                    print("%47s port %d (tc=%d color=%d -> egress_pcp=%d))"
                          % (" ", egres_ports[1], egress_tc, egress_color,
                             p2_egress_pcp))
                    print("%47s port %d (tc=%d color=%d -> egress_pcp=%d))"
                          % (" ", egres_ports[2], egress_tc, egress_color,
                             p3_egress_pcp))

                    send_packet(self, ingress_port, pkt)
                    verify_each_packet_on_multiple_port_lists(
                        self, flood_pkt_list, flood_port_list)
                    print("\tPacket flooded. ok")

        finally:
            pass

    def l2QosMapDifferentPCPToColorMultiIngresssPortTest(self):
        ''' L2 traffic test verifies the following:
            1. Many PCP to color mapping for various ingress ports
            The verification method:
                - SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR mapping defined for ingress
                and assigned to ports 0, 1, 2, and 3
                - SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P mapping defined for
                ingress and assigned to ports 0, 1, 2, and 3
                - various SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P mappings
                defined for egress and assigned to ports 0, 1, 2, and 3
                egress pcp = 2 x egress port - 1 + color
        '''
        print("l2QosMapDifferentPCPToColorMultiIngresssPortTest")

        # default PCP to TC mapping
        test_cases = []
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 0,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 1,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 2,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 3,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 4,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 5,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 6,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port0,
            'pcp': 7,
            'p0_pcp': None,
            'p1_pcp': 1,
            'p2_pcp': 3,
            'p3_pcp': 5
        })

        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 0,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 1,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 2,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 3,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 4,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 5,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 6,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })
        test_cases.append({
            'ingress_port': self.dev_port1,
            'pcp': 7,
            'p0_pcp': 1,
            'p1_pcp': None,
            'p2_pcp': 3,
            'p3_pcp': 5
        })

        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 0,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 1,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 2,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 3,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 4,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 5,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 6,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })
        test_cases.append({
            'ingress_port': self.dev_port2,
            'pcp': 7,
            'p0_pcp': 2,
            'p1_pcp': 2,
            'p2_pcp': None,
            'p3_pcp': 6
        })

        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 0,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 1,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 2,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 3,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 4,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 5,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 6,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })
        test_cases.append({
            'ingress_port': self.dev_port3,
            'pcp': 7,
            'p0_pcp': 3,
            'p1_pcp': 3,
            'p2_pcp': 5,
            'p3_pcp': None
        })

        try:
            for port, dot1p_to_tc, dot1p_color, tc_color_to_pcp in [
                    [self.port0, self.qos_dot1p_to_tc_map_id,
                     self.p1_qos_dot1p_to_color_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port1, self.qos_dot1p_to_tc_map_id,
                     self.p1_qos_dot1p_to_color_map_id,
                     self.p1_qos_tc_color_to_dot1q_id],
                    [self.port2, self.qos_dot1p_to_tc_map_id,
                     self.p2_qos_dot1p_to_color_map_id,
                     self.p2_qos_tc_color_to_dot1q_id],
                    [self.port3, self.qos_dot1p_to_tc_map_id,
                     self.p3_qos_dot1p_to_color_map_id,
                     self.p3_qos_tc_color_to_dot1q_id]]:
                # ingress set DOT1P -> TC
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)
                # ingress set DOT1P -> COLOR
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_color_map=dot1p_color)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_dot1p_to_color_map=True)
                self.assertEqual(attr['qos_dot1p_to_color_map'], dot1p_color)
                # egress set TC and COLOR -> DOT1Q
                status = sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dot1p_map=tc_color_to_pcp)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(
                    self.client, port, qos_tc_and_color_to_dot1p_map=True)
                self.assertEqual(attr['qos_tc_and_color_to_dot1p_map'],
                                 tc_color_to_pcp)

            for test in test_cases:
                ingress_port = test['ingress_port']
                if test['pcp'] is not None:
                    vlan = 1
                    ingress_pcp = str(test['pcp'])
                else:
                    vlan = 0
                    ingress_pcp = 'None'
                # define expected egress_pcp per egress port
                p0_egress_pcp = test['p0_pcp']  # port 0 and 1  maps to color 0
                p1_egress_pcp = test['p1_pcp']  # port 0 and 1  maps to color 0
                p2_egress_pcp = test['p2_pcp']  # port 2 maps to color yellow
                p3_egress_pcp = test['p3_pcp']  # port 3 maps to color red

                pkt = simple_tcp_packet(eth_dst='00:33:33:33:33:00',
                                        eth_src='00:33:33:33:33:11',
                                        dl_vlan_enable=True,
                                        vlan_vid=vlan,
                                        vlan_pcp=test['pcp'],
                                        pktlen=104)
                p0_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p0_egress_pcp,  # port1 tc_color-> dot1q mapping
                    pktlen=104)
                p1_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p1_egress_pcp,  # port1 tc_color-> dot1q mapping
                    pktlen=104)
                p2_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p2_egress_pcp,  # port2 tc_color-> dot1q mapping
                    pktlen=104)
                p3_exp_pkt = simple_tcp_packet(
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_vlan_enable=True,
                    vlan_vid=1,
                    vlan_pcp=p3_egress_pcp,  # port3 tc_color-> dot1q mapping
                    pktlen=104)

                egres_ports = []
                flood_port_list = []
                flood_pkt_list = []
                pkt_list = [p0_exp_pkt, p1_exp_pkt, p2_exp_pkt, p3_exp_pkt]
                egress_pcp_list = [p0_egress_pcp, p1_egress_pcp,
                                   p2_egress_pcp, p3_egress_pcp]
                egress_pcp = []

                for i, port in enumerate(self.dev_test_port_list):
                    if port == ingress_port:
                        continue
                    flood_port_list.append([port])
                    flood_pkt_list.append(pkt_list[i])
                    egres_ports.append(port)
                    egress_pcp.append(egress_pcp_list[i])
                print("Sending eth packet port %d (pcp=%s) -> "
                      " port %d (pcp=%d)"
                      % (ingress_port, ingress_pcp, egres_ports[0],
                         egress_pcp[0]))
                print("%47s port %d (egress_pcp=%d))" %
                      (" ", egres_ports[1], egress_pcp[1]))
                print("%47s port %d (egress_pcp=%d))" %
                      (" ", egres_ports[2], egress_pcp[2]))

                send_packet(self, ingress_port, pkt)
                verify_each_packet_on_multiple_port_lists(self, flood_pkt_list,
                                                          flood_port_list)
                print("\tPacket flooded. ok")

        finally:
            pass

    def runTest(self):
        try:
            self.l2QosMapPCPToColorDefaultMappingTest()
            self.l2QosMapMultiPCPToOneColorMappingTest()
            self.l2QosMapSamePCPToColorMultiIngresssPortTest()
            self.l2QosMapDifferentPCPToColorMultiIngresssPortTest()
        finally:
            pass


class L2QosMapPcpToTcTest(L2QosMapBaseClass):
    ''' L2 PCP to TC QOS map tests base class. '''

    def setUp(self):

        L2QosMapBaseClass.setUp(self)

    def l2QosMapPCPToTcDefaultMappingTest(self):
        ''' Test verifies the following:
            1. default L2 PCP to TC mapping (no mapping defined)
            The verification method:
                - setting the TC to QUEUE mapping
                - verification of the queue stats
        '''

        print("l2QosMapPCPToTcDefaultMappingTest")
        # default PCP to TC mapping
        test_cases = []
        # port default_tc Test Case
        test_cases.append({
            'pcp': 0,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 5,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        test_cases.append({
            'pcp': 0,
            'port_default_tc': 1,
            'queue': 1,
            'color': 0
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 2,
            'queue': 2,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 3,
            'queue': 3,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 4,
            'queue': 4,
            'color': 0
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 5,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 6,
            'queue': 6,
            'color': 0
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 7,
            'queue': 7,
            'color': 0
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'queue': 0,
            'color': 0
        })
        # Test configured default_tc
        # different default_tc per port
        # port 0 -> default_tc = 5 ingress
        # port 1 -> default_tc = 1 egress
        # port 2 -> default_tc = 2 egress
        # port 3 -> default_tc = 3 egress
        test_cases.append({
            'pcp': 0,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': None,
            'queue': 5,
            'color': 0
        })

        try:
            # setup tc to queue index mapping
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")

            # assign to port the tc_queue and tc_color_to_pcp qos map
            for port, tc_to_queue in [[self.port0, qos_tc_to_queue_map_id],
                                      [self.port1, qos_tc_to_queue_map_id],
                                      [self.port2, qos_tc_to_queue_map_id],
                                      [self.port3, qos_tc_to_queue_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=tc_to_queue)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'], tc_to_queue)

            # verify port default tc
            for port in [self.port0, self.port1, self.port2, self.port3]:
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True,
                                                     qos_default_tc=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], 0)
                self.assertEqual(attr['qos_default_tc'], 0)

            for test in test_cases:
                queue = test['queue']
                # setup port default_tc
                if test['port_default_tc'] is not None:
                    # every test port gets the same default_tc =
                    # test['port_default_tc']
                    port_default_tc = test['port_default_tc']
                    port_config = [[self.port0, port_default_tc],
                                   [self.port1, port_default_tc],
                                   [self.port2, port_default_tc],
                                   [self.port3, port_default_tc]]
                else:
                    # every port gets default_tc as its port number
                    # port 0 -> default tc = 5
                    # port 1 -> default tc = 1
                    # port 2 -> default tc = 2
                    # port 3 -> default tc = 3
                    port_config = [[self.port0, 5], [self.port1, 1],
                                   [self.port2, 2], [self.port3, 3]]

                for port, port_default_tc in port_config:
                    status = sai_thrift_set_port_attribute(
                        self.client, port, qos_default_tc=port_default_tc)
                    attr = sai_thrift_get_port_attribute(self.client,
                                                         port,
                                                         qos_default_tc=True)
                    self.assertEqual(attr['qos_default_tc'], port_default_tc)
                p1_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p2_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p3_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port3, queue, ['SAI_QUEUE_STAT_PACKETS'])
                if test['port_default_tc'] is not None:
                    port_default_tc = str(test['port_default_tc'])
                else:
                    port_default_tc = str(1)
                ingress_pcp = str(test['pcp'])
                print("Sending packet port %d (default_tc=%s, pcp=%s)"
                      " -> port %d (queue=%d, pcp=%d)"
                      % (self.dev_port0, port_default_tc,
                         ingress_pcp, self.dev_port1, queue, 1))
                print("\t\t\t\t\tport %d (queue=%d, pcp=%d))"
                      % (self.dev_port2, queue, 2))
                print("\t\t\t\t\tport %d (queue=%d, pcp=%d))"
                      % (self.dev_port3, queue, 3))

                ingress_pcp = test['pcp']
                pkt = simple_eth_raw_packet_with_taglist(
                    pktlen=104,
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_taglist_enable=True,
                    dl_vlan_pcp_list=[ingress_pcp],
                    dl_vlanid_list=[1])
                p1_exp_pkt = simple_eth_raw_packet_with_taglist(
                    pktlen=104,
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_taglist_enable=True,
                    dl_vlan_pcp_list=[1],
                    dl_vlanid_list=[1])
                p2_exp_pkt = simple_eth_raw_packet_with_taglist(
                    pktlen=104,
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_taglist_enable=True,
                    dl_vlan_pcp_list=[1],
                    dl_vlanid_list=[1])
                p3_exp_pkt = simple_eth_raw_packet_with_taglist(
                    pktlen=104,
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_taglist_enable=True,
                    dl_vlan_pcp_list=[3],
                    dl_vlanid_list=[1])

                test_port = self.dev_port0
                flood_port_list = [[self.dev_port1], [self.dev_port2],
                                   [self.dev_port3]]
                flood_pkt_list = [p1_exp_pkt, p2_exp_pkt, p3_exp_pkt]
                flood_pkt_list = [pkt, pkt, pkt]

                send_packet(self, test_port, pkt)
                verify_each_packet_on_multiple_port_lists(self, flood_pkt_list,
                                                          flood_port_list)
                print("\tPacket flooded. ok")
                p1_post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p2_post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p3_post_q_cnt = self.getPortQueueIndexStats(
                    self.port3, queue, ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    p1_initial_q_cnt + 1, p1_post_q_cnt,
                    'PORT1 queue {} packets counter {} != {}'.format(
                        queue, p1_initial_q_cnt + 1, p1_post_q_cnt))
                self.assertEqual(
                    p2_initial_q_cnt + 1, p2_post_q_cnt,
                    'PORT2 queue {} packets counter {} != {}'.format(
                        queue, p2_initial_q_cnt + 1, p2_post_q_cnt))
                self.assertEqual(
                    p3_initial_q_cnt + 1, p3_post_q_cnt,
                    'PORT3 queue {} packets counter {} != {}'.format(
                        queue, p3_initial_q_cnt + 1, p3_post_q_cnt))

        finally:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_to_queue_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_default_tc=0)
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)

    def l2QosMapMultiplePCPToOneTcMappingTest(self):
        ''' Test verifies the following:
            1. L2 traffic multiple PCP to TC mapping
            The verification method:
                - setting the TC to QUEUE mapping
                - verification of the queue stats
        '''

        print("l2QosMapMultiplePCPToOneTcMappingTest")
        test_cases = []
        # port default_tc Test Case
        test_cases.append({
            'pcp': 0,
            'port_default_tc': 0,
            'p1_queue': 3,
            'p2_queue': 3,
            'p3_queue': 3
        })
        test_cases.append({
            'pcp': 1,
            'port_default_tc': 0,
            'p1_queue': 3,
            'p2_queue': 3,
            'p3_queue': 3
        })
        test_cases.append({
            'pcp': 2,
            'port_default_tc': 0,
            'p1_queue': 3,
            'p2_queue': 3,
            'p3_queue': 3
        })
        test_cases.append({
            'pcp': 3,
            'port_default_tc': 0,
            'p1_queue': 3,
            'p2_queue': 3,
            'p3_queue': 3
        })
        test_cases.append({
            'pcp': 4,
            'port_default_tc': 0,
            'p1_queue': 7,
            'p2_queue': 7,
            'p3_queue': 7
        })
        test_cases.append({
            'pcp': 5,
            'port_default_tc': 0,
            'p1_queue': 7,
            'p2_queue': 7,
            'p3_queue': 7
        })
        test_cases.append({
            'pcp': 6,
            'port_default_tc': 0,
            'p1_queue': 7,
            'p2_queue': 7,
            'p3_queue': 7
        })
        test_cases.append({
            'pcp': 7,
            'port_default_tc': 0,
            'p1_queue': 7,
            'p2_queue': 7,
            'p3_queue': 7
        })

        try:
            print("Create dot1p -> tc qos mapping")
            ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [3, 3, 3, 3, 7, 7, 7, 7]
            qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_dot1p_list,
                ingress_tc_list)
            self.assertTrue(qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            print("Create tc -> queue index qos mapping")
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [3, 3, 3, 3, 7, 7, 7, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            # configure the ingress ports
            for port, dot1p_to_tc in [[self.port0, qos_dot1p_to_tc_map_id]]:
                # print("PORT 0x%x dot1p_to_tc=0x%x" %(port, dot1p_to_tc))
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)

            # configure the egress ports
            for port, tc_to_queue in [[self.port1, qos_tc_to_queue_map_id],
                                      [self.port2, qos_tc_to_queue_map_id],
                                      [self.port3, qos_tc_to_queue_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=tc_to_queue)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'], tc_to_queue)

            # verify port default tc
            for port in [self.port0, self.port1, self.port2, self.port3]:
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True,
                                                     qos_default_tc=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'], 0)
                self.assertEqual(attr['qos_default_tc'], 0)

            for test in test_cases:
                pcp = test['pcp']

                # setup port default_tc
                port_default_tc = 0
                if test['port_default_tc'] is not None:
                    port_default_tc = test['port_default_tc']
                for port in [self.port0]:
                    status = sai_thrift_set_port_attribute(
                        self.client, port, qos_default_tc=port_default_tc)
                    attr = sai_thrift_get_port_attribute(self.client,
                                                         port,
                                                         qos_default_tc=True)
                    self.assertEqual(attr['qos_default_tc'], port_default_tc)

                p1_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['p1_queue'], ['SAI_QUEUE_STAT_PACKETS'])
                p2_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['p2_queue'], ['SAI_QUEUE_STAT_PACKETS'])
                p3_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port3, test['p3_queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (pcp=%d) -> "
                      "port %d (port_default_tc=%d queue=%d)"
                      % (self.dev_port0, pcp, self.dev_port1,
                         test['port_default_tc'], test['p1_queue']))

                pkt = simple_eth_raw_packet_with_taglist(
                    pktlen=104,
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_taglist_enable=True,
                    dl_vlan_pcp_list=[pcp],
                    dl_vlanid_list=[1])

                test_port = self.dev_port0
                flood_port_list = [[self.dev_port1], [self.dev_port2],
                                   [self.dev_port3]]
                flood_pkt_list = [pkt, pkt, pkt]
                send_packet(self, test_port, pkt)
                verify_each_packet_on_multiple_port_lists(self, flood_pkt_list,
                                                          flood_port_list)
                print("\tPacket flooded to ports 1,2,3. ok")

                p1_post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['p1_queue'], ['SAI_QUEUE_STAT_PACKETS'])
                p2_post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, test['p2_queue'], ['SAI_QUEUE_STAT_PACKETS'])
                p3_post_q_cnt = self.getPortQueueIndexStats(
                    self.port3, test['p3_queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    p1_initial_q_cnt + 1, p1_post_q_cnt,
                    'PORT1 queue {} packets counter {} != {}'.format(
                        test['p1_queue'], p1_initial_q_cnt + 1, p1_post_q_cnt))
                self.assertEqual(
                    p2_initial_q_cnt + 1, p2_post_q_cnt,
                    'PORT2 queue {} packets counter {} != {}'.format(
                        test['p2_queue'], p2_initial_q_cnt + 1, p2_post_q_cnt))
                self.assertEqual(
                    p3_initial_q_cnt + 1, p3_post_q_cnt,
                    'PORT3 queue {} packets counter {} != {}'.format(
                        test['p3_queue'], p3_initial_q_cnt + 1, p3_post_q_cnt))

        finally:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_to_queue_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_default_tc=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dot1p_to_tc_map=0)
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dot1p_to_tc_map_id)

    def l2QosMapVariousPcpToTcManyIngressPortsTest(self):
        ''' Test verifies the following:
            1. L2 traffic multiple PCP to various TC mapping
            The verification method:
                - setting the TC to QUEUE mapping
                - verification of the queue stats
        '''

        print("l2QosMapVariousPcpToTcManyIngressPortsTest")
        try:
            print("Create and verify dot1p -> tc qos mapping")
            p0_qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_DOT1P_TO_TC, [0, 1, 2, 3, 4, 5, 6, 7],
                [4, 5, 6, 7, 0, 1, 2, 3],
                verify=True)
            # expected queue number formula
            # queue = (ingress port_number + 4 + pcp) mod 8
            self.assertTrue(p0_qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")
            p1_qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_DOT1P_TO_TC, [0, 1, 2, 3, 4, 5, 6, 7],
                [5, 6, 7, 0, 1, 2, 3, 4],
                verify=True)
            self.assertTrue(p1_qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")
            p2_qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_DOT1P_TO_TC, [0, 1, 2, 3, 4, 5, 6, 7],
                [6, 7, 0, 1, 2, 3, 4, 5],
                verify=True)
            self.assertTrue(p2_qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")
            p3_qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_DOT1P_TO_TC, [0, 1, 2, 3, 4, 5, 6, 7],
                [7, 0, 1, 2, 3, 4, 5, 6],
                verify=True)
            self.assertTrue(p3_qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            print("Create tc -> queue index qos mapping")
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE,
                [0, 1, 2, 3, 4, 5, 6, 7], [0, 1, 2, 3, 4, 5, 6, 7])
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            # configure the ingress ports
            for port, dot1p_to_tc in [[self.port0, p0_qos_dot1p_to_tc_map_id],
                                      [self.port1, p1_qos_dot1p_to_tc_map_id],
                                      [self.port2, p2_qos_dot1p_to_tc_map_id],
                                      [self.port3, p3_qos_dot1p_to_tc_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)

            # configure the egress ports tc -> queue mapping
            # same for all ports.
            for port, tc_to_queue in [[self.port0, qos_tc_to_queue_map_id],
                                      [self.port1, qos_tc_to_queue_map_id],
                                      [self.port2, qos_tc_to_queue_map_id],
                                      [self.port3, qos_tc_to_queue_map_id]]:

                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=tc_to_queue)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'], tc_to_queue)

            # verify port default_tc
            ports = [self.port0, self.port1, self.port2, self.port3]
            self.verifyPortDefaultDscpToTc(ports)

            for p_idx in range(0, len(self.dev_test_port_list)):
                test_port = self.dev_test_port_list[p_idx]
                print("Testing tx_port=%d" % (test_port))
                for pcp in [0, 1, 2, 3, 4, 5, 6, 7]:
                    pkt = simple_eth_raw_packet_with_taglist(
                        pktlen=104,
                        eth_dst='00:33:33:33:33:00',
                        eth_src='00:33:33:33:33:11',
                        dl_taglist_enable=True,
                        dl_vlan_pcp_list=[pcp],
                        dl_vlanid_list=[1])

                    flood_port_list = []
                    flood_pkt_list = []
                    for port in self.dev_test_port_list:
                        if port == test_port:
                            continue
                        flood_port_list.append([port])
                        flood_pkt_list.append(pkt)

                    port_queue = []
                    for port in range(0, len(self.dev_test_port_list)):
                        queue_index = (pcp + port + 4) % 8
                        port_queue.append(queue_index)

                    init_q_cnt = []
                    for port in [self.port0, self.port1, self.port2,
                                 self.port3]:
                        queue = port_queue[p_idx]
                        init_q_cnt.append(
                            self.getPortQueueIndexStats(
                                port, queue, ['SAI_QUEUE_STAT_PACKETS']))
                    print("Sending packet port %d (pcp=%d) -> "
                          "port %d (queue=%d)"
                          % (test_port, pcp, flood_port_list[0][0],
                             port_queue[p_idx]))
                    print("\t\t\t\t\tport %d (queue=%d)"
                          % (flood_port_list[1][0], port_queue[p_idx]))
                    print("\t\t\t\t\tport %d (queue=%d)"
                          % (flood_port_list[2][0], port_queue[p_idx]))

                    send_packet(self, test_port, pkt)
                    verify_each_packet_on_multiple_port_lists(
                        self, flood_pkt_list, flood_port_list)
                    print("\tPacket flooded to ports %s. ok" %
                          (flood_port_list))
                    print("\tVerify port queues packet counters.")

                    post_q_cnt = []
                    for port in [
                            self.port0, self.port1, self.port2, self.port3
                    ]:
                        post_q_cnt.append(
                            self.getPortQueueIndexStats(
                                port, port_queue[p_idx],
                                ['SAI_QUEUE_STAT_PACKETS']))

                    # verify the port queue counters
                    cnt_dict = {"init": init_q_cnt, "post": post_q_cnt}
                    self.verifyPortQueueCountersSamePcp(test_port, p_idx,
                                                        cnt_dict, port_queue)
                    print("\tok")

        finally:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_to_queue_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_default_tc=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dot1p_to_tc_map=0)

            sai_thrift_remove_qos_map(self.client, p0_qos_dot1p_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p1_qos_dot1p_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p2_qos_dot1p_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, p3_qos_dot1p_to_tc_map_id)
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)

    def verifyPortDefaultDscpToTc(self, ports):
        """
        Verifies port default tc

        Args:
            ports (list): list of ports
        """
        for port in ports:
            attr = sai_thrift_get_port_attribute(self.client,
                                                 port,
                                                 qos_dscp_to_tc_map=True,
                                                 qos_default_tc=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'], 0)
            self.assertEqual(attr['qos_default_tc'], 0)

    def verifyPortQueueCountersSamePcp(self, test_port, p_idx,
                                       cnt_dict, port_queue):
        """
        Verifies the port queue counters

        Args:
            test_port (int): test port number
            p_idx (int): port id
            cnt_dict (dict): dictionary of cnt lists
            port_queue (list): port queue list
        """
        i = 0
        for port in self.dev_test_port_list:
            if port == test_port:
                # counter should remain unchanged
                self.assertEqual(
                    cnt_dict["init"][i], cnt_dict["post"][i],
                    'PORT{} queue {} packets expected {} got {}'
                    .format(port, port_queue[p_idx], cnt_dict["init"][i],
                            cnt_dict["post"][i]))
            else:
                # counter should increase
                self.assertEqual(
                    cnt_dict["init"][i] + 1, cnt_dict["post"][i],
                    'PORT{} queue {} packets expected {} got {}'
                    .format(port, port_queue[p_idx],
                            cnt_dict["init"][i] + 1, cnt_dict["post"][i]))
            i += 1

    def l2QosMapSamePcpToTcManyIngressPortsTest(self):
        ''' Test verifies the following:
            1. L2 traffic same PCP to many TC mapping
            The verification method:
                - setting the TC to QUEUE mapping
                - verification of the queue stats
        '''

        print("l2QosMapSamePcpToTcManyIngressPortsTest")
        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 0,
            'p1_queue': 0,
            'p2_queue': 0,
            'p3_queue': 0
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 1,
            'p1_queue': 1,
            'p2_queue': 1,
            'p3_queue': 1
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 2,
            'p1_queue': 2,
            'p2_queue': 2,
            'p3_queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 3,
            'p1_queue': 3,
            'p2_queue': 3,
            'p3_queue': 3
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 4,
            'p1_queue': 4,
            'p2_queue': 4,
            'p3_queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 5,
            'p1_queue': 5,
            'p2_queue': 5,
            'p3_queue': 5
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 6,
            'p1_queue': 6,
            'p2_queue': 6,
            'p3_queue': 6
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'pcp': 7,
            'p1_queue': 7,
            'p2_queue': 7,
            'p3_queue': 7
        })

        try:
            print("Create dot1p -> tc qos mapping")
            ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_dot1p_list,
                ingress_tc_list)
            self.assertTrue(qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            print("Create tc -> queue index qos mapping")
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            # configure the ingress ports
            for port, dot1p_to_tc in [[self.port0, qos_dot1p_to_tc_map_id],
                                      [self.port1, qos_dot1p_to_tc_map_id],
                                      [self.port2, qos_dot1p_to_tc_map_id],
                                      [self.port3, qos_dot1p_to_tc_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)

            # configure the egress ports
            for port, tc_to_queue in [[self.port0, qos_tc_to_queue_map_id],
                                      [self.port1, qos_tc_to_queue_map_id],
                                      [self.port2, qos_tc_to_queue_map_id],
                                      [self.port3, qos_tc_to_queue_map_id]]:
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=tc_to_queue)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'], tc_to_queue)

            # verify port default_tc
            ports = [self.port0, self.port1, self.port2, self.port3]
            self.verifyPortDefaultDscpToTc(ports)

            for test_port in self.dev_test_port_list:
                print("Testing tx_port=%d" % (test_port))
                for test in test_cases:
                    pcp = test['pcp']
                    pkt = simple_eth_raw_packet_with_taglist(
                        pktlen=104,
                        eth_dst='00:33:33:33:33:00',
                        eth_src='00:33:33:33:33:11',
                        dl_taglist_enable=True,
                        dl_vlan_pcp_list=[pcp],
                        dl_vlanid_list=[1])

                    flood_port_list = []
                    flood_pkt_list = []
                    for port in self.dev_test_port_list:
                        if port == test_port:
                            continue
                        flood_port_list.append([port])
                        flood_pkt_list.append(pkt)

                    init_q_cnt = []
                    for port in [
                            self.port0, self.port1, self.port2, self.port3
                    ]:
                        init_q_cnt.append(
                            self.getPortQueueIndexStats(
                                port, test['p1_queue'],
                                ['SAI_QUEUE_STAT_PACKETS']))

                    print("Sending packet port %d (pcp=%d) -> "
                          "port %d (queue=%d)"
                          % (test_port, pcp, flood_port_list[0][0],
                             test['p1_queue']))
                    print("\t\t\t\t\tport %d (queue=%d)"
                          % (flood_port_list[1][0], test['p2_queue']))
                    print("\t\t\t\t\tport %d (queue=%d)"
                          % (flood_port_list[2][0], test['p3_queue']))

                    send_packet(self, test_port, pkt)
                    verify_each_packet_on_multiple_port_lists(
                        self, flood_pkt_list, flood_port_list)
                    print("\tPacket flooded to ports %s. ok" %
                          (flood_port_list))
                    print("\tVerify port queues packet counters.")
                    post_q_cnt = []
                    for port in [
                            self.port0, self.port1, self.port2, self.port3
                    ]:
                        post_q_cnt.append(
                            self.getPortQueueIndexStats(
                                port, test['p1_queue'],
                                ['SAI_QUEUE_STAT_PACKETS']))

                    # verify the port queue counters
                    self.verifyPortQueueCountersVariousPcp(
                        test_port, test, init_q_cnt, post_q_cnt)
                    print("\tok")

        finally:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_to_queue_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_default_tc=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dot1p_to_tc_map=0)
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dot1p_to_tc_map_id)

    def verifyPortQueueCountersVariousPcp(self, test_port, test, init_q_cnt,
                                          post_q_cnt):
        """
        Verifies the port queue counters

        Args:
            test_port (int): test port number
            test (dict): test dictionary
            init_q_cnt (list): init cnt list
            post_q_cnt (list): post cnt list
        """
        i = 0
        for port in self.dev_test_port_list:
            if port == test_port:
                # counter should remain unchanged
                self.assertEqual(
                    init_q_cnt[i], post_q_cnt[i],
                    'PORT{} queue {} packets expected {} == {}'
                    .format(port, test['p1_queue'], init_q_cnt[i],
                            post_q_cnt[i]))
            else:
                # counter should increase
                self.assertEqual(
                    init_q_cnt[i] + 1, post_q_cnt[i],
                    'PORT{} queue {} packets expected {} == {}'
                    .format(port, test['p1_queue'],
                            init_q_cnt[i] + 1, post_q_cnt[i]))
            i += 1

    def l2QosMapOneToOnePCPToTcMappingTest(self):
        ''' Test verifies the following:
            1. L2 traffic one to one PCP to TC mapping
            The verification method:
                - setting the TC to QUEUE mapping
                - verification of the queue stats
        '''

        print("l2QosMapOneToOnePCPToTcMappingTest")
        test_cases = []
        test_cases.append({'pcp': 0, 'queue': 0})
        test_cases.append({'pcp': 1, 'queue': 1})
        test_cases.append({'pcp': 2, 'queue': 2})
        test_cases.append({'pcp': 3, 'queue': 3})
        test_cases.append({'pcp': 4, 'queue': 4})
        test_cases.append({'pcp': 5, 'queue': 5})
        test_cases.append({'pcp': 6, 'queue': 6})
        test_cases.append({'pcp': 7, 'queue': 7})

        try:
            print("Create dot1p -> tc qos mapping")
            ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_dot1p_to_tc_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_dot1p_list,
                ingress_tc_list)
            self.assertTrue(qos_dot1p_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            print("Create tc -> queue index qos mapping")
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            # configure the ingress ports
            for port, dot1p_to_tc in [[self.port0, qos_dot1p_to_tc_map_id]]:
                # print("PORT 0x%x dot1p_to_tc=0x%x" %(port, dot1p_to_tc))
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_dot1p_to_tc_map=dot1p_to_tc)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dot1p_to_tc_map=True)
                self.assertEqual(attr['qos_dot1p_to_tc_map'], dot1p_to_tc)

            # configure the egress ports
            for port, tc_to_queue in [[self.port1, qos_tc_to_queue_map_id],
                                      [self.port2, qos_tc_to_queue_map_id],
                                      [self.port3, qos_tc_to_queue_map_id]]:
                # print("PORT 0x%x tc_to_queue=0x%x" %(port, tc_to_queue))
                status = sai_thrift_set_port_attribute(
                    self.client, port, qos_tc_to_queue_map=tc_to_queue)
                self.assertEqual(status, SAI_STATUS_SUCCESS,
                                 "Failed to set port attribute")
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_tc_to_queue_map=True)
                self.assertEqual(attr['qos_tc_to_queue_map'], tc_to_queue)

            # verify port default tc
            for port in [self.port0, self.port1, self.port2, self.port3]:
                attr = sai_thrift_get_port_attribute(self.client,
                                                     port,
                                                     qos_dscp_to_tc_map=True,
                                                     qos_default_tc=True)
                self.assertEqual(attr['qos_dscp_to_tc_map'], 0)
                self.assertEqual(attr['qos_default_tc'], 0)

            for test in test_cases:
                pcp = test['pcp']
                queue = test['queue']

                # setup port default_tc
                port_default_tc = 0
                for port in [self.port0]:
                    attr = sai_thrift_get_port_attribute(self.client,
                                                         port,
                                                         qos_default_tc=True)
                    self.assertEqual(attr['qos_default_tc'], port_default_tc)

                p1_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p2_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port2, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p3_initial_q_cnt = self.getPortQueueIndexStats(
                    self.port3, queue, ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending eth packet port %d (pcp=%d) -> "
                      "port %d (queue=%d)"
                      % (self.dev_port0, pcp, self.dev_port1,
                         queue))
                print("\t\t\t\t\tport %d (queue=%d)"
                      % (self.dev_port2, queue))
                print("\t\t\t\t\tport %d (queue=%d)"
                      % (self.dev_port3, queue))

                pkt = simple_eth_raw_packet_with_taglist(
                    pktlen=104,
                    eth_dst='00:33:33:33:33:00',
                    eth_src='00:33:33:33:33:11',
                    dl_taglist_enable=True,
                    dl_vlan_pcp_list=[pcp],
                    dl_vlanid_list=[1])

                test_port = self.dev_port0
                flood_port_list = [[self.dev_port1], [self.dev_port2],
                                   [self.dev_port3]]
                flood_pkt_list = [pkt, pkt, pkt]
                send_packet(self, test_port, pkt)
                verify_each_packet_on_multiple_port_lists(self, flood_pkt_list,
                                                          flood_port_list)
                print("\tPacket flooded to ports 1,2,3. ok")

                p1_post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p2_post_q_cnt = self.getPortQueueIndexStats(
                    self.port2, queue, ['SAI_QUEUE_STAT_PACKETS'])
                p3_post_q_cnt = self.getPortQueueIndexStats(
                    self.port3, queue, ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    p1_initial_q_cnt + 1, p1_post_q_cnt,
                    'PORT1 queue {} packets counter {} != {}'.format(
                        queue, p1_initial_q_cnt + 1, p1_post_q_cnt))
                self.assertEqual(
                    p2_initial_q_cnt + 1, p2_post_q_cnt,
                    'PORT2 queue {} packets counter {} != {}'.format(
                        queue, p2_initial_q_cnt + 1, p2_post_q_cnt))
                self.assertEqual(
                    p3_initial_q_cnt + 1, p3_post_q_cnt,
                    'PORT3 queue {} packets counter {} != {}'.format(
                        queue, p3_initial_q_cnt + 1, p3_post_q_cnt))

        finally:
            for port in [self.port0, self.port1, self.port2, self.port3]:
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_tc_to_queue_map=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_default_tc=0)
                sai_thrift_set_port_attribute(self.client,
                                              port,
                                              qos_dot1p_to_tc_map=0)
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)
            sai_thrift_remove_qos_map(self.client, qos_dot1p_to_tc_map_id)

    def runTest(self):
        try:
            # PCP -> Tc Map
            self.l2QosMapPCPToTcDefaultMappingTest()
            self.l2QosMapMultiplePCPToOneTcMappingTest()
            self.l2QosMapOneToOnePCPToTcMappingTest()
            self.l2QosMapSamePcpToTcManyIngressPortsTest()
            self.l2QosMapVariousPcpToTcManyIngressPortsTest()

        finally:
            pass

    def tearDown(self):
        L2QosMapBaseClass.tearDown(self)


class QosMapCreateModifyTest(L2QosMapBaseClass):
    ''' QOS map create and modify test base class.
    '''

    def setUp(self):
        L2QosMapBaseClass.setUp(self)

    def qosMapDscpToTcCreateModifyTest(self):
        ''' QOS DSCP -> TC map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapDscpToTcCreateModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create dscp -> tc qos mapping")
            ingress_dscp_list = [63, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_DSCP_TO_TC,
                ingress_dscp_list,
                ingress_tc_list,
                verify=False)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({'dscp': [0, 1, 2, 4, 5], 'tc': [0, 1, 2, 4, 5]})
            test_cases.append({'dscp': [5, 6, 7], 'tc': [2, 2, 2]})
            test_cases.append({'dscp': [0], 'tc': [0]})
            test_cases.append({'dscp': [], 'tc': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map dscp -> "
                      "tc with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_dscp_to_tc_map_id,
                        SAI_QOS_MAP_TYPE_DSCP_TO_TC,
                        test['dscp'], test['tc']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)

    def qosMapTcToQueueModifyTest(self):
        ''' QOS TC -> QUEUE map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapTcToQueueModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create tc -> queue index qos mapping")
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_QUEUE, ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({
                'tc': [0, 1, 2, 4, 5],
                'queue': [0, 1, 2, 4, 5]
            })
            test_cases.append({
                'tc': [0, 1, 2, 4, 5],
                'queue': [0, 0, 0, 0, 0]})
            test_cases.append({
                'tc': [0, 1, 2, 4, 5, 6, 7],
                'queue': [0, 0, 0, 0, 0, 7, 7]
            })
            test_cases.append({'tc': [5, 6, 7], 'queue': [2, 2, 2]})
            test_cases.append({'tc': [0], 'queue': [0]})
            i = 0
            for test in test_cases:
                print("[tc]%d]: Update existing qos_map tc -> "
                      "queue index with new map_to_value_list" % (i))

                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_tc_to_queue_map_id,
                        SAI_QOS_MAP_TYPE_TC_TO_QUEUE,
                        test['tc'], test['queue']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)

    def qosMapDscpToColorCreateModifyTest(self):
        ''' QOS DSCP -> COLOR map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapDscpToColorCreateModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create dscp -> color qos mapping")
            ingress_dscp_list = [63, 1, 2, 3, 4, 5, 6, 7]
            ingress_color_list = [0, 1, 2, 2, 2, 2, 2, 2]
            qos_dscp_to_color_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DSCP_TO_COLOR, ingress_dscp_list,
                ingress_color_list)
            self.assertTrue(qos_dscp_to_color_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({
                'dscp': [0, 1, 2, 4, 5],
                'color': [0, 1, 2, 0, 0]
            })
            test_cases.append({
                'dscp': [0, 1, 2, 4, 5, 19, 20],
                'color': [0, 1, 2, 0, 0, 2, 2]
            })
            test_cases.append({'dscp': [5, 6, 7], 'color': [2, 2, 2]})
            test_cases.append({'dscp': [0], 'color': [0]})
            test_cases.append({'dscp': [], 'color': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map dscp -> "
                      "color with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_dscp_to_color_map_id,
                        SAI_QOS_MAP_TYPE_DSCP_TO_COLOR,
                        test['dscp'], test['color']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_dscp_to_color_map_id)

    def qosMapPrioToQueueModifyTest(self):
        ''' QOS PRIO -> QUEUE map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapPrioToQueueModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create prio -> queue index qos mapping")
            ingress_prio_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_queue_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_prio_to_queue_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_QUEUE,
                ingress_prio_list, ingress_queue_list)
            self.assertTrue(qos_prio_to_queue_map_id != 0,
                            "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({
                'prio': [0, 1, 2, 4, 5],
                'queue': [0, 1, 2, 4, 5]
            })
            test_cases.append({'prio': [5, 6, 7], 'queue': [2, 2, 2]})
            test_cases.append({'prio': [7], 'queue': [7]})
            test_cases.append({'prio': [], 'queue': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map prio -> "
                      " queue index with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_prio_to_queue_map_id,
                        SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_QUEUE, test['prio'],
                        test['queue']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_prio_to_queue_map_id)

    def qosMapDot1ToColorCreateModifyTest(self):
        ''' QOS DOT1P -> COLOR map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapDot1ToColorCreateModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create dot1p -> color qos mapping")
            ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_color_list = [0, 0, 0, 1, 1, 1, 2, 2]
            qos_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR,
                ingress_dot1p_list, ingress_color_list)
            self.assertTrue(qos_map_id != 0, "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({
                'dot1p': [0, 1, 2, 4, 5],
                'color': [0, 1, 2, 2, 2]
            })
            test_cases.append({'dot1p': [5, 6, 7], 'color': [2, 2, 2]})
            test_cases.append({'dot1p': [5, 6, 7], 'color': [0, 0, 0]})
            test_cases.append({'dot1p': [5, 6, 7, 0], 'color': [0, 0, 0, 1]})
            test_cases.append({'dot1p': [0], 'color': [0]})
            test_cases.append({'dot1p': [], 'color': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map dot1p -> "
                      " color with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_map_id,
                        SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR,
                        test['dot1p'], test['color']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_map_id)

    def qosMapPfcPrioToPrioGroupCreateModifyTest(self):
        ''' QOS PFC PRIORITY -> PRIORITY GROUP map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapPfcPrioToPrioGroupCreateModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create PFC priority -> priority group mapping")
            ingress_pfc_prio_list = [0, 1, 2]
            ingress_pg_list = [3, 4, 5]
            qos_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP,
                ingress_pfc_prio_list, ingress_pg_list)
            self.assertTrue(qos_map_id != 0, "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({
                'pfc_prio': [0, 1, 2, 4, 5],
                'pg': [0, 1, 2, 2, 2]
            })
            test_cases.append({'pfc_prio': [5, 6, 7], 'pg': [2, 2, 2]})
            test_cases.append({'pfc_prio': [5, 6, 7], 'pg': [0, 2, 2]})
            test_cases.append({'pfc_prio': [5, 6, 7], 'pg': [0, 2, 3]})
            test_cases.append({'pfc_prio': [5, 6, 7, 0], 'pg': [0, 0, 0, 1]})
            test_cases.append({'pfc_prio': [0], 'pg': [0]})
            test_cases.append({'pfc_prio': [], 'pg': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map pfc_priority -> "
                      " priority_group with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_map_id,
                        SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP,
                        test['pfc_prio'], test['pg']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_map_id)

    def qosMapDot1ToTcCreateModifyTest(self):
        ''' QOS DOT1P -> TC map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapDot1ToTcCreateModifyTest")
        try:
            # setup dot1p to tc mapping
            print("Create dot1p -> tc qos mapping")
            ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_DOT1P_TO_TC, ingress_dot1p_list,
                ingress_tc_list)
            self.assertTrue(qos_map_id != 0, "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({'dot1p': [0, 1, 2, 4, 5],
                               'tc': [0, 1, 2, 4, 5]})
            test_cases.append({'dot1p': [5, 6, 7], 'tc': [2, 2, 2]})
            test_cases.append({'dot1p': [0], 'tc': [0]})
            test_cases.append({'dot1p': [], 'tc': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map dot1p -> "
                      "tc with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_map_id,
                        SAI_QOS_MAP_TYPE_DOT1P_TO_TC,
                        test['dot1p'], test['tc']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_map_id)

    def qosMapTcColorToDscpCreateModifyTest(self):
        ''' QOS TC + COLOR -> DSCP map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapTcColorToDscpCreateModifyTest")
        try:
            # setup tc to queue index mapping
            print("Create tc and color -> dscp qos mapping")
            ingress_tc_color_list = [[0, 1], [1, 1], [2, 0], [3, 0], [4, 1],
                                     [5, 0], [6, 1], [7, 0]]
            ingress_dscp_list = [0, 21, 32, 13, 44, 25, 16, 9]
            # error case to demonstrate SWI-3525
            # ingress_tc_color_list = [[0, 3]]
            # ingress_dscp_list = [0]
            qos_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
                ingress_tc_color_list, ingress_dscp_list)
            self.assertTrue(qos_map_id != 0, "Failed to create qos_map")
            print("\tok")
            test_cases = []
            test_cases.append({
                'tc_color': [[1, 0], [2, 0], [7, 0]],
                'dscp': [0, 1, 2]
            })
            test_cases.append({
                'tc_color': [[1, 1], [1, 0], [2, 0]],
                'dscp': [0, 1, 2]
            })
            test_cases.append({
                'tc_color': [[1, 1], [2, 2], [3, 1], [4, 0]],
                'dscp': [12, 9, 27, 32]
            })
            test_cases.append({'tc_color': [], 'dscp': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map_id tc_color -> "
                      " dscp with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_map_id,
                        SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
                        test['tc_color'], test['dscp']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_map_id)

    def qosMapTcColorToDot1pCreateModifyTest(self):
        ''' QOS TC + COLOR -> DOT1P map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''
        print("qosMapTcColorToDot1pCreateModifyTest")

        try:
            # setup tc to queue index mapping
            print("Create tc and color -> dot1p qos mapping")
            ingress_tc_color_list = [[0, 1], [1, 1], [2, 0], [3, 0], [4, 1],
                                     [5, 0], [6, 1], [7, 0]]
            ingress_dot1p_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
                ingress_tc_color_list, ingress_dot1p_list)
            self.assertTrue(qos_map_id != 0, "Failed to create qos_map")
            print("\tok")
            test_cases = []
            test_cases.append({
                'tc_color': [[1, 2], [2, 0], [7, 0]],
                'dot1p': [0, 1, 2]
            })
            test_cases.append({
                'tc_color': [[1, 1], [1, 0], [2, 0]],
                'dot1p': [0, 1, 2]
            })
            test_cases.append({
                'tc_color': [[1, 1], [2, 2], [3, 1], [4, 0]],
                'dot1p': [7, 4, 5, 7]
            })
            test_cases.append({'tc_color': [], 'dot1p': []})
            i = 0
            for test in test_cases:
                print("[tc:%d]: Update existing qos_map tc_color -> "
                      " dot1p with new map_to_value_list" % (i))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_map_id,
                        SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
                        test['tc_color'], test['dot1p']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_map_id)

    def qosMapTcPgCreateModifyTest(self):
        ''' QOS TC -> PRIORITY GROUP map create and modify test.
            Test verifies creation of the qos map object.
            In addition it:
            - verifies created qos map and its map_to_value_list.
            - updates the created qos map object map_to_value_list
              with the new data list and verifies it
        '''

        print("qosMapTcPgCreateModifyTest")
        try:
            print("Create tc -> priority group qos mapping")
            ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_pg_list = [0, 1, 2, 3, 4, 5, 6, 7]
            qos_map_id = create_and_verify_qos_map(
                self.client, SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
                ingress_tc_list, ingress_pg_list)
            self.assertTrue(qos_map_id != 0, "Failed to create qos_map")
            print("\tok")

            test_cases = []
            test_cases.append({'tc': [0, 1, 2], 'pg': [0, 1, 2]})
            test_cases.append({'tc': [0, 1, 2], 'pg': [2, 1, 0]})
            test_cases.append({'tc': [0], 'pg': [7]})
            test_cases.append({'tc': [0], 'pg': [6]})
            test_cases.append({
                'tc': [0, 1, 2, 3, 4, 5, 6, 7],
                'pg': [0, 0, 0, 0, 1, 2, 3, 4]
            })
            test_cases.append({'tc': [], 'pg': []})
            i = 0
            for test in test_cases:
                print("%d: Update qos_map tc [%s] -> pg [%s]" %
                      (i, test['tc'], test['pg']))
                self.assertEqual(
                    update_and_verify_qos_map(
                        self.client, qos_map_id,
                        SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP, test['tc'],
                        test['pg']), True,
                    "Failed verify updated qos_map attribute")
                print("\tok")
                i += 1
        finally:
            sai_thrift_remove_qos_map(self.client, qos_map_id)

    def runTest(self):
        try:
            self.qosMapTcToQueueModifyTest()
            self.qosMapTcColorToDscpCreateModifyTest()
            self.qosMapDscpToTcCreateModifyTest()
            self.qosMapDscpToColorCreateModifyTest()
            self.qosMapPrioToQueueModifyTest()
            self.qosMapDot1ToTcCreateModifyTest()
            self.qosMapDot1ToColorCreateModifyTest()
            self.qosMapTcColorToDot1pCreateModifyTest()
            self.qosMapPfcPrioToPrioGroupCreateModifyTest()
            self.qosMapTcPgCreateModifyTest()
        finally:
            pass

    def tearDown(self):
        L2QosMapBaseClass.tearDown(self)


@disabled
class L3QoSAclTest(L3QosMapBaseClass):
    '''
    ACL QoS Test class.
    This is to verify QOS_ACTIONS_IN_IP_ACL_ENABLE p4
    '''

    def setUp(self):
        L3QosMapBaseClass.setUp(self)

    def runTest(self):
        print('\nRunning tests:')
        self.testIngressAclTC()

    def tearDown(self):
        L3QosMapBaseClass.tearDown(self)

    def testIngressAclTC(self):
        '''
        This test uses ACL entries on ingress port to set the TC value.
        The match is based on IP protocol field. On the egress port,
        a qos_map is used to map TC to QID.
        If there is no match, packet will map to TC 0 and QID 0.
        '''
        print("testIngressAclTC")
        test_cases = []
        test_cases.append({
            'tx_port': self.dev_port0,
            'proto': 6,
            'tc': 1,
            'queue': 2
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'proto': 17,
            'tc': 2,
            'queue': 4
        })
        test_cases.append({
            'tx_port': self.dev_port0,
            'proto': 1,
            'tc': 0,
            'queue': 0
        })

        try:
            # create ACL table
            table_stage = SAI_ACL_STAGE_INGRESS
            table_bind_points = [SAI_ACL_BIND_POINT_TYPE_PORT]
            table_bind_point_type_list = sai_thrift_s32_list_t(
                count=len(table_bind_points), int32list=table_bind_points)
            acl_table = sai_thrift_create_acl_table(
                self.client,
                acl_stage=table_stage,
                acl_bind_point_type_list=table_bind_point_type_list,
                field_src_ip=True,
                field_dst_ip=True,
                field_ip_protocol=True)

            # create 2 ACL entries
            src_ip = '192.168.0.1'
            src_ip_mask = '255.255.255.255'
            src_ip_t = sai_thrift_acl_field_data_t(
                data=sai_thrift_acl_field_data_data_t(ip4=src_ip),
                mask=sai_thrift_acl_field_data_mask_t(ip4=src_ip_mask))

            dst_ip = '10.10.10.11'
            dst_ip_mask = '255.255.255.255'
            dst_ip_t = sai_thrift_acl_field_data_t(
                data=sai_thrift_acl_field_data_data_t(ip4=dst_ip),
                mask=sai_thrift_acl_field_data_mask_t(ip4=dst_ip_mask))

            # ip proto 6
            ip_protocol = sai_thrift_acl_field_data_t(
                enable=True,
                data=sai_thrift_acl_field_data_data_t(u8=6),
                mask=sai_thrift_acl_field_data_mask_t(u8=127))

            # set tc to 1
            action_set_tc = sai_thrift_acl_action_data_t(
                enable=True,
                parameter=sai_thrift_acl_action_parameter_t(u8=1))

            packet_action = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    s32=SAI_PACKET_ACTION_FORWARD))

            acl_entry1 = sai_thrift_create_acl_entry(
                self.client,
                table_id=acl_table,
                priority=10,
                field_src_ip=src_ip_t,
                field_dst_ip=dst_ip_t,
                field_ip_protocol=ip_protocol,
                action_set_tc=action_set_tc,
                action_packet_action=packet_action)

            # ip proto 17
            ip_protocol = sai_thrift_acl_field_data_t(
                enable=True,
                data=sai_thrift_acl_field_data_data_t(u8=17),
                mask=sai_thrift_acl_field_data_mask_t(u8=127))

            # set tc to 2
            action_set_tc = sai_thrift_acl_action_data_t(
                enable=True,
                parameter=sai_thrift_acl_action_parameter_t(u8=2))

            acl_entry2 = sai_thrift_create_acl_entry(
                self.client,
                table_id=acl_table,
                priority=20,
                field_src_ip=src_ip_t,
                field_dst_ip=dst_ip_t,
                field_ip_protocol=ip_protocol,
                action_set_tc=action_set_tc,
                action_packet_action=packet_action)

            # create ACL counters
            acl_counter_ingress1 = sai_thrift_create_acl_counter(
                self.client, table_id=acl_table)
            acl_counter_ingress2 = sai_thrift_create_acl_counter(
                self.client, table_id=acl_table)

            # attach ACL counters to ACL entries
            action_counter_ingress = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=acl_counter_ingress1),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, acl_entry1,
                action_counter=action_counter_ingress)

            action_counter_ingress = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=acl_counter_ingress2),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, acl_entry2,
                action_counter=action_counter_ingress)

            # bind ACL table to ingress port
            status = sai_thrift_set_port_attribute(
                self.client, self.port0, ingress_acl=acl_table)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")

            # pylint: disable=pointless-string-statement
            '''
            # setup dscp to tc mapping
            # TODO -- need to check ACL override after P4 change
            ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
            ingress_tc_list = [1, 1, 1, 1, 6, 6, 6, 6]
            qos_dscp_to_tc_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_DSCP_TO_TC,
                ingress_dscp_list,
                ingress_tc_list)
            self.assertTrue(qos_dscp_to_tc_map_id != 0,
                "Failed to create dscp_to_tc qos_map")

            status = sai_thrift_set_port_attribute(
                self.client, self.port0,
                qos_dscp_to_tc_map=qos_dscp_to_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")

            attr = sai_thrift_get_port_attribute(
                self.client,
                self.port0,
                qos_dscp_to_tc_map=True)
            self.assertEqual(attr['qos_dscp_to_tc_map'],
                qos_dscp_to_tc_map_id)
            '''

            # setup tc to queue index mapping
            ingress_tc_list = [1, 2]
            ingress_queue_list = [2, 4]
            qos_tc_to_queue_map_id = create_and_verify_qos_map(
                self.client,
                SAI_QOS_MAP_TYPE_TC_TO_QUEUE,
                ingress_tc_list,
                ingress_queue_list)
            self.assertTrue(qos_tc_to_queue_map_id != 0,
                            "Failed to create tc_to_queue qos_map")

            # bind TC-> QID map to ingress port
            status = sai_thrift_set_port_attribute(
                self.client, self.port0,
                qos_tc_to_queue_map=qos_tc_to_queue_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")

            attr = sai_thrift_get_port_attribute(
                self.client, self.port0, qos_tc_to_queue_map=True)
            self.assertEqual(attr['qos_tc_to_queue_map'],
                             qos_tc_to_queue_map_id)

            for test in test_cases:
                ip_proto = test['proto']
                pkt = simple_ip_packet(
                    eth_dst=ROUTER_MAC,
                    eth_src='00:22:22:22:22:22',
                    ip_dst='10.10.10.11',
                    ip_src='192.168.0.1',
                    ip_proto=ip_proto,
                    ip_ttl=64)
                exp_pkt = simple_ip_packet(
                    eth_dst='00:11:22:33:44:04',
                    eth_src=ROUTER_MAC,
                    ip_dst='10.10.10.11',
                    ip_src='192.168.0.1',
                    ip_proto=ip_proto,
                    ip_ttl=63)

                initial_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                print("Sending packet port %d (ip_proto=%d) ->"
                      " port %d (tc=%d => queue=%d)"
                      % (test['tx_port'], ip_proto, self.dev_port1, test['tc'],
                         test['queue']))
                send_packet(self, test['tx_port'], pkt)
                verify_packet(self, exp_pkt, self.dev_port1)

                post_q_cnt = self.getPortQueueIndexStats(
                    self.port1, test['queue'], ['SAI_QUEUE_STAT_PACKETS'])
                self.assertEqual(
                    initial_q_cnt + 1, post_q_cnt,
                    'queue {} packets counter {} != {}'.format(
                        test['queue'], initial_q_cnt + 1, post_q_cnt))
        finally:
            # cleanup ACL
            action_counter_ingress = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(oid=0),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, acl_entry1,
                action_counter=action_counter_ingress)
            sai_thrift_set_acl_entry_attribute(
                self.client, acl_entry2,
                action_counter=action_counter_ingress)
            sai_thrift_set_acl_counter_attribute(
                self.client, acl_counter_ingress1, packets=None)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter_ingress1, packets=True)
            self.assertEqual(packets['packets'], 0)
            sai_thrift_set_acl_counter_attribute(
                self.client, acl_counter_ingress2, packets=None)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter_ingress2, packets=True)
            self.assertEqual(packets['packets'], 0)
            sai_thrift_remove_acl_counter(self.client, acl_counter_ingress1)
            sai_thrift_remove_acl_counter(self.client, acl_counter_ingress2)
            sai_thrift_set_port_attribute(self.client, self.port0,
                                          ingress_acl=0)
            sai_thrift_remove_acl_entry(self.client, acl_entry1)
            sai_thrift_remove_acl_entry(self.client, acl_entry2)
            sai_thrift_remove_acl_table(self.client, acl_table)

            # pylint: disable=pointless-string-statement
            '''
            # TODO cleanup dscp to tc map
            status = sai_thrift_set_port_attribute(
                self.client, self.port0, qos_dscp_to_tc_map=int(
                    SAI_NULL_OBJECT_ID))
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                "Failed to set port attribute")
            #sai_thrift_remove_qos_map(self.client, qos_dscp_to_tc_map_id)
            '''
            status = sai_thrift_set_port_attribute(
                self.client, self.port0, qos_tc_to_queue_map=int(
                    SAI_NULL_OBJECT_ID))
            self.assertEqual(status, SAI_STATUS_SUCCESS,
                             "Failed to set port attribute")
            sai_thrift_remove_qos_map(self.client, qos_tc_to_queue_map_id)


@group('disabled')
@group('hw')
class PortTxPFCStatsTest(SaiHelperBase):
    """ Test port attributes """
    def setUp(self):
        super(PortTxPFCStatsTest, self).setUp()
        self.port = None
        self.ingr_pool = None
        self.buffer_profile = None
        self.qos_dscp_tc_map_id = None
        self.ppg_list = []
        self.pfc_to_pg_map_id = [0] * 8
        self.tc_to_pg_map_id = [0] * 8
        self.ports = []
        self.port1_bp = None
        self.port2_bp = None
        self.port3_bp = None
        self.port4_bp = None
        self.vlan100 = None
        self.vlan100_member1 = None
        self.vlan100_member2 = None
        self.vlan100_member3 = None
        self.vlan100_member4 = None
        self.fdb_entry = None

    def runTest(self):
        try:
            self.portTest()
        finally:
            pass

    def portTest(self):
        """ Get port PFC TX statistics """

        sai_list = sai_thrift_u32_list_t(count=1, uint32list=[124])
        port124 = sai_thrift_create_port(
            self.client,
            hw_lane_list=sai_list,
            speed=10000,
            priority_flow_control_mode=0,  # flow_control (0 == PFC)
            priority_flow_control=8,  # pfc map
            admin_state=True)
        self.assertTrue(port124 != 0, "Failed to create port")
        self.ports.append(port124)

        sai_list = sai_thrift_u32_list_t(count=1, uint32list=[125])
        port125 = sai_thrift_create_port(
            self.client,
            hw_lane_list=sai_list,
            speed=10000,
            priority_flow_control_mode=0,  # flow_control (0 == PFC)
            priority_flow_control=8,  # pfc map
            admin_state=True)
        self.assertTrue(port125 != 0, "Failed to create port")
        self.ports.append(port125)

        sai_list = sai_thrift_u32_list_t(count=1, uint32list=[126])
        port126 = sai_thrift_create_port(
            self.client,
            hw_lane_list=sai_list,
            speed=10000,
            priority_flow_control_mode=0,  # flow_control (0 == PFC)
            priority_flow_control=8,  # pfc map
            admin_state=True)
        self.assertTrue(port126 != 0, "Failed to create port")
        self.ports.append(port126)

        self.vlan100 = sai_thrift_create_vlan(self.client, vlan_id=100)

        self.port1_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=port124,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)
        self.port2_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=port125,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)
        self.port3_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=port126,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)
        self.port4_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port1,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)

        self.vlan100_member1 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port1_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan100_member2 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port2_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan100_member3 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port3_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan100_member4 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port4_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)

        mac = '00:BA:7E:F0:00:0A'
        mac_action = SAI_PACKET_ACTION_FORWARD

        self.fdb_entry = sai_thrift_fdb_entry_t(
            switch_id=self.switch_id, mac_address=mac, bv_id=self.vlan100)

        sai_thrift_create_fdb_entry(
            self.client,
            self.fdb_entry,
            type=SAI_FDB_ENTRY_TYPE_STATIC,
            bridge_port_id=self.port4_bp,
            packet_action=mac_action)

        sai_thrift_set_port_attribute(
            self.client, port124, port_vlan_id=100)
        sai_thrift_set_port_attribute(
            self.client, port125, port_vlan_id=100)
        sai_thrift_set_port_attribute(
            self.client, port126, port_vlan_id=100)
        sai_thrift_set_port_attribute(
            self.client, self.port1, port_vlan_id=100)

        reserved_buf_size = 1024
        buf_size = reserved_buf_size * 1000

        self.ingr_pool = sai_thrift_create_buffer_pool(
            self.client, type=SAI_BUFFER_POOL_TYPE_INGRESS,
            threshold_mode=SAI_BUFFER_POOL_THRESHOLD_MODE_STATIC,
            xoff_size=10080,
            size=buf_size)
        self.assertGreater(self.ingr_pool, 0)

        self.buffer_profile = sai_thrift_create_buffer_profile(
            self.client, pool_id=self.ingr_pool,
            reserved_buffer_size=reserved_buf_size,
            threshold_mode=SAI_BUFFER_PROFILE_THRESHOLD_MODE_STATIC,
            shared_static_th=reserved_buf_size,
            xoff_th=512,
            xon_th=1024)
        self.assertGreater(self.buffer_profile, 0)

        for port in self.ports:
            for ppg_index in range(8):
                ppg = sai_thrift_create_ingress_priority_group(
                    self.client,
                    port=port,
                    index=ppg_index,
                    buffer_profile=self.buffer_profile)
                self.assertNotEqual(
                    ppg, 0, "Failed to create priority group")
                self.ppg_list.append(ppg)

            # verify number of ppg groups
            attr = sai_thrift_get_port_attribute(
                self.client, port, number_of_ingress_priority_groups=True)
            nbr_groups = attr['number_of_ingress_priority_groups']
            ingress_priority_group_list = sai_thrift_u32_list_t(
                count=nbr_groups, uint32list=[])
            attr = sai_thrift_get_port_attribute(
                self.client,
                port,
                ingress_priority_group_list=ingress_priority_group_list)
            self.assertTrue(
                attr['ingress_priority_group_list'].count == nbr_groups,
                "Failed to verify ingress priority groups")
            self.assertTrue(nbr_groups == 9,
                            "Failed to verify ingress priority groups")

        ingress_key_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.qos_dscp_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_key_list,
            ingress_tc_list)
        self.assertTrue(self.qos_dscp_tc_map_id != 0,
                        "Failed to create qos_map")

        ingress_pfc_prio_list = [0]
        ingress_pg_list = [0]
        self.pfc_to_pg_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP,
            ingress_pfc_prio_list, ingress_pg_list)
        self.assertTrue(self.pfc_to_pg_map_id != 0,
                        "Failed to create qos_map")

        ingress_tc_list = [0]
        ingress_pg_list = [0]
        self.tc_to_pg_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
            ingress_tc_list, ingress_pg_list)
        self.assertTrue(self.tc_to_pg_map_id != 0,
                        "Failed to create qos_map")

        for port in self.ports:
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS)

            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=self.pfc_to_pg_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS)

            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=self.tc_to_pg_map_id)
            self.assertEqual(status, SAI_STATUS_SUCCESS)

            stats = sai_thrift_get_port_stats(self.client, port)

            # Flood port 1 using traffic sent with Ixia
            # and then check the statistics
            # input()

            for i in range(0, 8):
                stats_string = "SAI_PORT_STAT_PFC_" + str(i) + "_TX_PKTS"
                counter = stats[stats_string]
                print(str(stats_string) + " : " + str(counter))
                stats_string = "SAI_PORT_STAT_PFC_" + str(i) + \
                               "_TX_PAUSE_DURATION"
                duration = stats[stats_string]
                print(str(stats_string) + " : " + str(duration))

    def tearDown(self):
        for port in self.ports:
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                port_vlan_id=0)
            self.assertEqual(status, SAI_STATUS_SUCCESS)
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_to_priority_group_map=0)
            self.assertEqual(status, SAI_STATUS_SUCCESS)
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_pfc_priority_to_priority_group_map=0)
            self.assertEqual(status, SAI_STATUS_SUCCESS)
            status = sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_dscp_to_tc_map=0)
            self.assertEqual(status, SAI_STATUS_SUCCESS)
        status = sai_thrift_set_port_attribute(
            self.client,
            self.port1,
            port_vlan_id=0)
        self.assertEqual(status, SAI_STATUS_SUCCESS)
        sai_thrift_remove_qos_map(self.client, self.tc_to_pg_map_id)
        sai_thrift_remove_qos_map(self.client, self.pfc_to_pg_map_id)
        sai_thrift_remove_qos_map(self.client, self.qos_dscp_tc_map_id)
        for ppg in self.ppg_list:
            sai_thrift_remove_ingress_priority_group(
                self.client, ppg)
        sai_thrift_remove_buffer_profile(self.client, self.buffer_profile)
        sai_thrift_remove_buffer_pool(self.client, self.ingr_pool)

        sai_thrift_remove_fdb_entry(self.client, self.fdb_entry)
        sai_thrift_remove_vlan_member(self.client, self.vlan100_member1)
        sai_thrift_remove_vlan_member(self.client, self.vlan100_member2)
        sai_thrift_remove_vlan_member(self.client, self.vlan100_member3)
        sai_thrift_remove_vlan_member(self.client, self.vlan100_member4)
        sai_thrift_remove_bridge_port(self.client, self.port1_bp)
        sai_thrift_remove_bridge_port(self.client, self.port2_bp)
        sai_thrift_remove_bridge_port(self.client, self.port3_bp)
        sai_thrift_remove_bridge_port(self.client, self.port4_bp)
        sai_thrift_remove_vlan(self.client, self.vlan100)

        for port in self.ports:
            sai_thrift_remove_port(self.client, port)

        super(PortTxPFCStatsTest, self).tearDown()


class EgressPcpDscpMapL2Test(SaiHelperBase):
    '''
    Tests if PCP and DSCP are updated if both maps are attached to the port
    for the L2 configuration and ACL with set tc action,
    DSCP -> color ingress mapping and [TC, color] -> DSCP, PCP mapping
    '''

    def setUp(self):
        super(EgressPcpDscpMapL2Test, self).setUp()

        self.vlan100 = sai_thrift_create_vlan(self.client, vlan_id=100)

        self.port24_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port24,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)
        self.port25_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port25,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)

        sai_thrift_set_port_attribute(
            self.client, self.port24, port_vlan_id=100)
        sai_thrift_set_port_attribute(
            self.client, self.port25, port_vlan_id=100)

        action_type = [SAI_ACL_ACTION_TYPE_SET_TC]
        qos_action_type_list = sai_thrift_s32_list_t(
            count=len(action_type), int32list=action_type)

        table_stage = SAI_ACL_STAGE_INGRESS

        bpoints = [SAI_ACL_BIND_POINT_TYPE_SWITCH]
        bpoint_type_list = sai_thrift_s32_list_t(
            count=len(bpoints), int32list=bpoints)

        acl_range_type = sai_thrift_s32_list_t(count=0, int32list=[])
        self.qos_acl_table = sai_thrift_create_acl_table(
            self.client,
            acl_stage=table_stage,
            acl_bind_point_type_list=bpoint_type_list,
            acl_action_type_list=qos_action_type_list,
            field_acl_range_type=acl_range_type,
            field_in_ports=True,
            field_outer_vlan_pri=True)
        self.assertNotEqual(self.qos_acl_table, 0)

        group_type = SAI_ACL_TABLE_GROUP_TYPE_PARALLEL
        self.acl_group = sai_thrift_create_acl_table_group(
            self.client,
            acl_stage=table_stage,
            acl_bind_point_type_list=bpoint_type_list,
            type=group_type)
        self.assertNotEqual(self.acl_group, 0)

        self.acl_group_member = sai_thrift_create_acl_table_group_member(
            self.client,
            acl_table_group_id=self.acl_group,
            acl_table_id=self.qos_acl_table)
        self.assertNotEqual(self.acl_group_member, 0)

        # setup action for catch all entry
        action_tc_set = sai_thrift_acl_action_data_t(
            enable=True,
            parameter=sai_thrift_acl_action_parameter_t(u8=5))

        in_ports = [self.port24]
        in_ports_list_t = sai_thrift_acl_field_data_t(
            data=sai_thrift_acl_field_data_data_t(
                objlist=sai_thrift_object_list_t(
                    count=len(in_ports),
                    idlist=in_ports)))

        self.acl_entry = sai_thrift_create_acl_entry(
            self.client,
            table_id=self.qos_acl_table,
            priority=10,
            action_set_tc=action_tc_set,
            field_in_ports=in_ports_list_t)

        self.acl_counter = sai_thrift_create_acl_counter(
            self.client, table_id=self.acl_group)

        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=self.acl_counter),
            enable=True)

        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)

        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 0)
        self.acl_cnt = packets['packets']

        sai_thrift_set_switch_attribute(
            self.client, ingress_acl=self.acl_group)

        ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_color_list = [0, 0, 0, 1, 1, 1, 2, 2]
        self.qos_dscp_to_color_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_COLOR, ingress_dscp_list,
            ingress_color_list)
        self.assertTrue(self.qos_dscp_to_color_map_id != 0,
                        "Failed to create qos_map")

        status = sai_thrift_set_port_attribute(
            self.client,
            self.port24,
            qos_dscp_to_color_map=self.qos_dscp_to_color_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS)

        self.egress_tc_color_list = [
            [0, 0],
            [1, 0],
            [2, 0],
            [3, 0],
            [4, 0],
            [5, 0],
            [6, 0],
            [7, 0],  # green
            [0, 1],
            [1, 1],
            [2, 1],
            [3, 1],
            [4, 1],
            [5, 1],
            [6, 1],
            [7, 1],  # yellow
            [0, 2],
            [1, 2],
            [2, 2],
            [3, 2],
            [4, 2],
            [5, 2],
            [6, 2],
            [7, 2]  # red
        ]

        egress_dscp_list = [
            0, 1, 2, 3, 4, 5, 6, 7,  # mapping green
            8, 9, 10, 11, 12, 13, 14, 15,  # mapping yellow
            16, 17, 18, 19, 20, 21, 22, 23  # mapping red
        ]
        self.qos_tc_color_to_dscp_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
            self.egress_tc_color_list, egress_dscp_list)
        self.assertTrue(self.qos_tc_color_to_dscp_map_id != 0,
                        "Failed to create qos_map")

        egress_pcp_list = [
            1, 1, 1, 1, 1, 1, 1, 1,  # pcp for green
            2, 2, 2, 2, 2, 2, 2, 2,  # pcp for yellow
            3, 3, 3, 3, 3, 3, 3, 3,  # pcp for red
        ]

        self.qos_tc_color_to_dot1p_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
            self.egress_tc_color_list, egress_pcp_list)
        self.assertTrue(self.qos_tc_color_to_dot1p_id != 0,
                        "Failed to create qos_map")

    def runTest(self):
        self.negativeTaggedTest()
        self.negativeUntaggedTest()
        status = sai_thrift_set_port_attribute(
            self.client,
            self.port25,
            qos_tc_and_color_to_dscp_map=self.qos_tc_color_to_dscp_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS)
        status = sai_thrift_set_port_attribute(
            self.client,
            self.port25,
            qos_tc_and_color_to_dot1p_map=self.qos_tc_color_to_dot1p_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS)
        self.ipv4L2SwitchingTaggedTest()
        self.ipv6L2SwitchingTaggedTest()
        self.mappingUpdateUntaggedTest()

    def negativeTaggedTest(self):
        """Test traffic without egress mapping with tagged vlan"""
        try:
            macv4 = '00:11:11:11:11:11'
            mac_action = SAI_PACKET_ACTION_FORWARD

            fdb_v4_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                                  mac_address=macv4,
                                                  bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(
                self.client,
                fdb_v4_entry,
                type=SAI_FDB_ENTRY_TYPE_STATIC,
                bridge_port_id=self.port25_bp,
                packet_action=mac_action)

            vlan100_member1 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port24_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)
            vlan100_member2 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port25_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)

            ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                ip_dscp=7)

            exp_ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                ip_dscp=7)

            send_packet(self, self.dev_port24, ip_pkt)
            verify_packet(self, exp_ip_pkt, self.dev_port25)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, self.acl_counter, packets=True)
            self.assertEqual(packets['packets'], 1)
            time.sleep(8)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_v4_entry)
            sai_thrift_remove_vlan_member(self.client, vlan100_member1)
            sai_thrift_remove_vlan_member(self.client, vlan100_member2)

    def negativeUntaggedTest(self):
        """Test traffic without egress  mapping with untagged vlan"""
        try:
            macv4 = '00:11:11:11:11:11'
            mac_action = SAI_PACKET_ACTION_FORWARD

            fdb_v4_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                                  mac_address=macv4,
                                                  bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(
                self.client,
                fdb_v4_entry,
                type=SAI_FDB_ENTRY_TYPE_STATIC,
                bridge_port_id=self.port25_bp,
                packet_action=mac_action)

            vlan100_member1 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port24_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
            vlan100_member2 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port25_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)

            ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                ip_dscp=7)

            exp_ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                ip_dscp=7)

            send_packet(self, self.dev_port24, ip_pkt)
            verify_packet(self, exp_ip_pkt, self.dev_port25)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, self.acl_counter, packets=True)
            self.assertEqual(packets['packets'], 2)
            time.sleep(8)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_v4_entry)
            sai_thrift_remove_vlan_member(self.client, vlan100_member1)
            sai_thrift_remove_vlan_member(self.client, vlan100_member2)

    def ipv4L2SwitchingTaggedTest(self):
        """ Test for IPv4 traffic """
        try:
            macv4 = '00:11:11:11:11:11'
            mac_action = SAI_PACKET_ACTION_FORWARD

            fdb_v4_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                                  mac_address=macv4,
                                                  bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(
                self.client,
                fdb_v4_entry,
                type=SAI_FDB_ENTRY_TYPE_STATIC,
                bridge_port_id=self.port25_bp,
                packet_action=mac_action)

            vlan100_member1 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port24_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)
            vlan100_member2 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port25_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)

            ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                ip_dscp=7)

            exp_ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                vlan_pcp=3,
                ip_dscp=21)

            send_packet(self, self.dev_port24, ip_pkt)
            verify_packet(self, exp_ip_pkt, self.dev_port25)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, self.acl_counter, packets=True)
            self.assertEqual(packets['packets'], 3)
            time.sleep(8)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_v4_entry)
            sai_thrift_remove_vlan_member(self.client, vlan100_member1)
            sai_thrift_remove_vlan_member(self.client, vlan100_member2)

    def ipv6L2SwitchingTaggedTest(self):
        """ Test for IPv6 traffic """
        try:
            macv6 = '00:11:11:11:11:11:11'
            mac_action = SAI_PACKET_ACTION_FORWARD

            fdb_v6_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                                  mac_address=macv6,
                                                  bv_id=self.vlan100)

            sai_thrift_create_fdb_entry(
                self.client,
                fdb_v6_entry,
                type=SAI_FDB_ENTRY_TYPE_STATIC,
                bridge_port_id=self.port25_bp,
                packet_action=mac_action)

            vlan100_member1 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port24_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)
            vlan100_member2 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port25_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)

            ip_pkt = simple_ipv6ip_packet(
                eth_dst='00:11:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ipv6_src='1::1',
                ipv6_dst='1::2',
                ipv6_hlim=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                ipv6_dscp=5)

            exp_ip_pkt = simple_ipv6ip_packet(
                eth_dst='00:11:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ipv6_src='1::1',
                ipv6_dst='1::2',
                ipv6_hlim=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                vlan_pcp=2,
                ipv6_dscp=13)

            send_packet(self, self.dev_port24, ip_pkt)
            verify_packet(self, exp_ip_pkt, self.dev_port25)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, self.acl_counter, packets=True)
            self.assertEqual(packets['packets'], 4)
            time.sleep(8)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_v6_entry)
            sai_thrift_remove_vlan_member(self.client, vlan100_member1)
            sai_thrift_remove_vlan_member(self.client, vlan100_member2)

    def mappingUpdateUntaggedTest(self):
        """ Map update test"""
        try:
            macv4 = '00:11:11:11:11:11'
            mac_action = SAI_PACKET_ACTION_FORWARD

            fdb_v4_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                                  mac_address=macv4,
                                                  bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(
                self.client,
                fdb_v4_entry,
                type=SAI_FDB_ENTRY_TYPE_STATIC,
                bridge_port_id=self.port25_bp,
                packet_action=mac_action)

            vlan100_member1 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port24_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
            vlan100_member2 = sai_thrift_create_vlan_member(
                self.client,
                vlan_id=self.vlan100,
                bridge_port_id=self.port25_bp,
                vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_TAGGED)

            egress_dscp_list = [
                40, 41, 42, 43, 44, 45, 46, 47,  # mapping green
                48, 49, 50, 51, 52, 53, 54, 55,  # mapping yellow
                56, 57, 58, 59, 60, 61, 62, 63  # mapping red
            ]

            qos_map_list = create_qos_map_to_value_list(
                SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
                self.egress_tc_color_list,
                egress_dscp_list)

            status = sai_thrift_set_qos_map_attribute(
                self.client, self.qos_tc_color_to_dscp_map_id, qos_map_list)
            self.assertEqual(status, SAI_STATUS_SUCCESS)

            egress_pcp_list = [
                4, 4, 4, 4, 4, 4, 4, 4,  # pcp for green
                5, 5, 5, 5, 5, 5, 5, 5,  # pcp for yellow
                6, 6, 6, 6, 6, 6, 6, 6,  # pcp for red
            ]

            qos_map_list = create_qos_map_to_value_list(
                SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
                self.egress_tc_color_list,
                egress_pcp_list)

            status = sai_thrift_set_qos_map_attribute(
                self.client, self.qos_tc_color_to_dot1p_id, qos_map_list)
            self.assertEqual(status, SAI_STATUS_SUCCESS)

            ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                ip_dscp=2)

            exp_ip_pkt = simple_ipv4ip_packet(
                eth_dst='00:11:11:11:11:11',
                eth_src=ROUTER_MAC,
                ip_src='192.168.0.1',
                ip_dst='192.168.0.2',
                ip_ttl=64,
                dl_vlan_enable=True,
                vlan_vid=100,
                vlan_pcp=4,
                ip_dscp=45)

            send_packet(self, self.dev_port24, ip_pkt)
            verify_packet(self, exp_ip_pkt, self.dev_port25)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, self.acl_counter, packets=True)
            self.assertEqual(packets['packets'], 5)
            time.sleep(8)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_v4_entry)
            sai_thrift_remove_vlan_member(self.client, vlan100_member1)
            sai_thrift_remove_vlan_member(self.client, vlan100_member2)

    def tearDown(self):
        #  cleanup acl group member, table
        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=0),
            enable=True)
        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)
        sai_thrift_set_acl_counter_attribute(
            self.client, self.acl_counter, packets=None)
        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 0)
        sai_thrift_remove_acl_counter(
            self.client, self.acl_counter)

        sai_thrift_set_switch_attribute(self.client, ingress_acl=0)
        sai_thrift_remove_acl_entry(self.client, self.acl_entry)
        sai_thrift_remove_acl_table_group_member(
            self.client, self.acl_group_member)
        sai_thrift_remove_acl_table(self.client, self.qos_acl_table)
        sai_thrift_remove_acl_table_group(self.client, self.acl_group)

        sai_thrift_set_port_attribute(
            self.client, self.port24, qos_dscp_to_color_map=0)
        sai_thrift_set_port_attribute(
            self.client, self.port25, qos_tc_and_color_to_dscp_map=0)
        sai_thrift_set_port_attribute(
            self.client, self.port25, qos_tc_and_color_to_dot1p_map=0)

        sai_thrift_remove_qos_map(
            self.client, self.qos_dscp_to_color_map_id)
        sai_thrift_remove_qos_map(
            self.client, self.qos_tc_color_to_dot1p_id)
        sai_thrift_remove_qos_map(
            self.client, self.qos_tc_color_to_dscp_map_id)

        sai_thrift_set_port_attribute(self.client, self.port24, port_vlan_id=0)
        sai_thrift_set_port_attribute(self.client, self.port25, port_vlan_id=0)

        sai_thrift_remove_vlan(self.client, self.vlan100)

        sai_thrift_remove_bridge_port(self.client, self.port24_bp)
        sai_thrift_remove_bridge_port(self.client, self.port25_bp)

        super(EgressPcpDscpMapL2Test, self).tearDown()


class EgressDscpMapL3Test(SaiHelper):
    '''
    Tests if DSCP is updated for the L3 configuration,
    ACL with set color action, DSCP -> TC ingress mapping
    and [TC, color] -> DSCP, PCP mapping
    '''
    def setUp(self):
        super(EgressDscpMapL3Test, self).setUp()

        dmac = '00:11:22:33:44:55'

        self.nhop = sai_thrift_create_next_hop(
            self.client, ip=sai_ipaddress('10.10.10.2'),
            router_interface_id=self.port10_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        self.neighbor_entry = sai_thrift_neighbor_entry_t(
            rif_id=self.port10_rif, ip_address=sai_ipaddress('10.10.10.2'))
        sai_thrift_create_neighbor_entry(self.client, self.neighbor_entry,
                                         dst_mac_address=dmac)

        self.route_entry = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('10.10.10.1/32'))
        sai_thrift_create_route_entry(self.client, self.route_entry,
                                      next_hop_id=self.nhop)

        action_type = [SAI_ACL_ACTION_TYPE_SET_PACKET_COLOR]
        qos_action_type_list = sai_thrift_s32_list_t(
            count=len(action_type), int32list=action_type)

        table_stage = SAI_ACL_STAGE_INGRESS

        bpoints = [SAI_ACL_BIND_POINT_TYPE_PORT]
        bpoint_type_list = sai_thrift_s32_list_t(
            count=len(bpoints), int32list=bpoints)

        acl_range_type = sai_thrift_s32_list_t(count=0, int32list=[])
        self.qos_acl_table = sai_thrift_create_acl_table(
            self.client,
            acl_stage=table_stage,
            acl_bind_point_type_list=bpoint_type_list,
            acl_action_type_list=qos_action_type_list,
            field_acl_range_type=acl_range_type,
            field_in_ports=True,
            field_outer_vlan_pri=True)
        self.assertNotEqual(self.qos_acl_table, 0)

        group_type = SAI_ACL_TABLE_GROUP_TYPE_PARALLEL
        self.acl_group = sai_thrift_create_acl_table_group(
            self.client,
            acl_stage=table_stage,
            acl_bind_point_type_list=bpoint_type_list,
            type=group_type)
        self.assertNotEqual(self.acl_group, 0)

        self.acl_group_member = sai_thrift_create_acl_table_group_member(
            self.client,
            acl_table_group_id=self.acl_group,
            acl_table_id=self.qos_acl_table)
        self.assertNotEqual(self.acl_group_member, 0)

        #  setup action for catch all entries
        action_color_set = sai_thrift_acl_action_data_t(
            enable=True,
            parameter=sai_thrift_acl_action_parameter_t(
                s32=SAI_PACKET_COLOR_YELLOW))

        in_ports = [self.port11]
        in_ports_list_t = sai_thrift_acl_field_data_t(
            data=sai_thrift_acl_field_data_data_t(
                objlist=sai_thrift_object_list_t(
                    count=len(in_ports),
                    idlist=in_ports)))

        # Color test temporarily disabled
        self.acl_entry = sai_thrift_create_acl_entry(
            self.client,
            table_id=self.qos_acl_table,
            priority=10,
            action_set_packet_color=action_color_set,
            field_in_ports=in_ports_list_t)

        self.acl_counter = sai_thrift_create_acl_counter(
            self.client, table_id=self.qos_acl_table)

        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=self.acl_counter),
            enable=True)

        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)

        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 0)
        self.acl_cnt = packets['packets']

        sai_thrift_set_switch_attribute(
            self.client, ingress_acl=self.qos_acl_table)

        ingress_dscp_list = [0, 1, 2, 3, 4, 5, 6, 7]
        ingress_tc_list = [0, 1, 2, 3, 4, 5, 6, 7]
        self.qos_dscp_tc_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_DSCP_TO_TC, ingress_dscp_list,
            ingress_tc_list)
        self.assertTrue(self.qos_dscp_tc_map_id != 0,
                        "Failed to create qos_map")

        status = sai_thrift_set_port_attribute(
            self.client,
            self.port11,
            qos_dscp_to_tc_map=self.qos_dscp_tc_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS)

        self.egress_tc_color_list = [
            [0, 0],
            [1, 0],
            [2, 0],
            [3, 0],
            [4, 0],
            [5, 0],
            [6, 0],
            [7, 0],  # green
            [0, 1],
            [1, 1],
            [2, 1],
            [3, 1],
            [4, 1],
            [5, 1],
            [6, 1],
            [7, 1],  # yellow
            [0, 2],
            [1, 2],
            [2, 2],
            [3, 2],
            [4, 2],
            [5, 2],
            [6, 2],
            [7, 2],  # red
        ]

        egress_dscp_list = [
            0, 1, 2, 3, 4, 5, 6, 7,  # mapping green
            8, 9, 10, 11, 12, 13, 14, 15,  # mapping yellow
            16, 17, 18, 19, 20, 21, 22, 23  # mapping red
        ]
        self.qos_tc_color_to_dscp_map_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
            self.egress_tc_color_list, egress_dscp_list)
        self.assertTrue(self.qos_tc_color_to_dscp_map_id != 0,
                        "Failed to create qos_map")

    def runTest(self):
        print('\nRunning tests:')
        self.negativeTest()
        status = sai_thrift_set_port_attribute(
            self.client,
            self.port10,
            qos_tc_and_color_to_dscp_map=self.qos_tc_color_to_dscp_map_id)
        self.assertEqual(status, SAI_STATUS_SUCCESS)
        self.dscpL3MappingTest()
        self.mappingUpdateTest()

    def negativeTest(self):
        """Test traffic without egress  mapping"""
        pkt = simple_tcp_packet(
            eth_dst=ROUTER_MAC,
            eth_src='00:22:22:22:22:22',
            ip_dst='10.10.10.1',
            ip_src='192.168.0.1',
            ip_id=105,
            ip_ttl=64,
            ip_dscp=6)

        exp_pkt = simple_tcp_packet(
            eth_dst='00:11:22:33:44:55',
            eth_src=ROUTER_MAC,
            ip_dst='10.10.10.1',
            ip_src='192.168.0.1',
            ip_id=105,
            ip_ttl=63,
            ip_dscp=6)

        send_packet(self, self.dev_port11, pkt)
        verify_packet(self, exp_pkt, self.dev_port10)
        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 1)
        time.sleep(8)

    def dscpL3MappingTest(self):
        """ DSCP mapping test """

        pkt = simple_tcp_packet(
            eth_dst=ROUTER_MAC,
            eth_src='00:22:22:22:22:22',
            ip_dst='10.10.10.1',
            ip_src='192.168.0.1',
            ip_id=105,
            ip_ttl=64,
            ip_dscp=6)

        exp_pkt = simple_tcp_packet(
            eth_dst='00:11:22:33:44:55',
            eth_src=ROUTER_MAC,
            ip_dst='10.10.10.1',
            ip_src='192.168.0.1',
            ip_id=105,
            ip_ttl=63,
            ip_dscp=14)

        send_packet(self, self.dev_port11, pkt)
        verify_packet(self, exp_pkt, self.dev_port10)
        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 2)
        time.sleep(8)

    def mappingUpdateTest(self):
        """ Map update test """

        egress_dscp_list = [
            40, 41, 42, 43, 44, 45, 46, 47,  # mapping green
            48, 49, 50, 51, 52, 53, 54, 55,  # mapping yellow
            56, 57, 58, 59, 60, 61, 62, 63  # mapping red
        ]

        qos_map_list = create_qos_map_to_value_list(
            SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
            self.egress_tc_color_list,
            egress_dscp_list)

        status = sai_thrift_set_qos_map_attribute(
            self.client, self.qos_tc_color_to_dscp_map_id, qos_map_list)
        self.assertEqual(status, SAI_STATUS_SUCCESS)

        pkt = simple_tcp_packet(
            eth_dst=ROUTER_MAC,
            eth_src='00:22:22:22:22:22',
            ip_dst='10.10.10.1',
            ip_src='192.168.0.1',
            ip_id=105,
            ip_ttl=64,
            ip_dscp=4)

        exp_pkt = simple_tcp_packet(
            eth_dst='00:11:22:33:44:55',
            eth_src=ROUTER_MAC,
            ip_dst='10.10.10.1',
            ip_src='192.168.0.1',
            ip_id=105,
            ip_ttl=63,
            ip_dscp=52)

        send_packet(self, self.dev_port11, pkt)
        verify_packet(self, exp_pkt, self.dev_port10)
        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 3)
        time.sleep(8)

    def tearDown(self):
        sai_thrift_remove_route_entry(self.client, self.route_entry)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor_entry)
        sai_thrift_remove_next_hop(self.client, self.nhop)

        #  cleanup acl group member, table
        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=0),
            enable=True)
        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)
        sai_thrift_set_acl_counter_attribute(
            self.client, self.acl_counter, packets=None)
        packets = sai_thrift_get_acl_counter_attribute(
            self.client, self.acl_counter, packets=True)
        self.assertEqual(packets['packets'], 0)
        sai_thrift_remove_acl_counter(
            self.client, self.acl_counter)

        sai_thrift_set_switch_attribute(self.client, ingress_acl=0)
        sai_thrift_remove_acl_entry(self.client, self.acl_entry)
        sai_thrift_remove_acl_table_group_member(
            self.client, self.acl_group_member)
        sai_thrift_remove_acl_table(self.client, self.qos_acl_table)
        sai_thrift_remove_acl_table_group(self.client, self.acl_group)

        sai_thrift_set_port_attribute(
            self.client, self.port11, qos_dscp_to_tc_map=0)
        sai_thrift_set_port_attribute(
            self.client, self.port10, qos_tc_and_color_to_dscp_map=0)

        sai_thrift_remove_qos_map(
            self.client, self.qos_dscp_tc_map_id)
        sai_thrift_remove_qos_map(
            self.client, self.qos_tc_color_to_dscp_map_id)

        super(EgressDscpMapL3Test, self).tearDown()


class EgressPcpDscpMapSviTest(SaiHelper):
    """
    This class contains base router interface tests for SVI RIFs
    """

    def setUp(self):
        super(EgressPcpDscpMapSviTest, self).setUp()

        self.ports = [self.port10, self.port24, self.port25, self.port26]

        self.port24_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port24,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)
        self.port25_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port25,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)
        self.port26_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port26,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)

        # vlan100 with members port24, port25 and port26
        self.vlan100 = sai_thrift_create_vlan(self.client, vlan_id=100)
        self.vlan_member1 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port24_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan_member2 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port25_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan_member3 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=self.port26_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)
        sai_thrift_set_port_attribute(
            self.client, self.port24, port_vlan_id=100)
        sai_thrift_set_port_attribute(
            self.client, self.port25, port_vlan_id=100)
        sai_thrift_set_port_attribute(
            self.client, self.port26, port_vlan_id=100)

        # create vlan100_rif
        self.vlan100_rif = sai_thrift_create_router_interface(
            self.client,
            type=SAI_ROUTER_INTERFACE_TYPE_VLAN,
            virtual_router_id=self.default_vrf,
            vlan_id=self.vlan100)

        self.dmac1 = '00:11:22:33:44:55'
        self.dmac2 = '00:22:22:33:44:55'
        self.dmac3 = '00:33:22:33:44:55'
        self.dmac4 = '00:44:22:33:44:55'

        # create nhop1, nhop2 & nhop3 on SVI
        self.nhop1 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('10.10.0.1'),
            router_interface_id=self.vlan100_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        self.neighbor1 = sai_thrift_neighbor_entry_t(
            rif_id=self.vlan100_rif, ip_address=sai_ipaddress('10.10.0.1'))
        sai_thrift_create_neighbor_entry(
            self.client, self.neighbor1, dst_mac_address=self.dmac1)
        self.route_entry1 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('10.10.10.1/32'))
        sai_thrift_create_route_entry(
            self.client, self.route_entry1, next_hop_id=self.nhop1)

        self.neighbor2 = sai_thrift_neighbor_entry_t(
            rif_id=self.vlan100_rif, ip_address=sai_ipaddress('10.10.0.2'))
        sai_thrift_create_neighbor_entry(
            self.client, self.neighbor2, dst_mac_address=self.dmac2)
        self.nhop2 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('10.10.0.2'),
            router_interface_id=self.vlan100_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        self.route_entry2 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('10.10.10.2/32'))
        sai_thrift_create_route_entry(
            self.client, self.route_entry2, next_hop_id=self.nhop2)

        self.nhop3 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('10.10.0.3'),
            router_interface_id=self.vlan100_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        self.neighbor3 = sai_thrift_neighbor_entry_t(
            rif_id=self.vlan100_rif, ip_address=sai_ipaddress('10.10.0.3'))
        sai_thrift_create_neighbor_entry(
            self.client, self.neighbor3, dst_mac_address=self.dmac3)
        self.route_entry3 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('10.10.10.3/32'))
        sai_thrift_create_route_entry(
            self.client, self.route_entry3, next_hop_id=self.nhop3)

        # create nhop and route to L2 intf
        self.nhop4 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('11.11.0.2'),
            router_interface_id=self.port10_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        self.neighbor4 = sai_thrift_neighbor_entry_t(
            rif_id=self.port10_rif, ip_address=sai_ipaddress('11.11.0.2'))
        sai_thrift_create_neighbor_entry(
            self.client, self.neighbor4, dst_mac_address=self.dmac4)
        self.route_entry4 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('11.11.11.1/32'))
        sai_thrift_create_route_entry(
            self.client, self.route_entry4, next_hop_id=self.nhop4)

        # Acl configuration
        action_type = [SAI_ACL_ACTION_TYPE_SET_TC,
                       SAI_ACL_ACTION_TYPE_SET_PACKET_COLOR]
        qos_action_type_list = sai_thrift_s32_list_t(
            count=len(action_type), int32list=action_type)

        table_stage = SAI_ACL_STAGE_INGRESS

        bpoints = [SAI_ACL_BIND_POINT_TYPE_PORT]
        bpoint_type_list = sai_thrift_s32_list_t(
            count=len(bpoints), int32list=bpoints)

        acl_range_type = sai_thrift_s32_list_t(count=0, int32list=[])
        self.qos_acl_table = sai_thrift_create_acl_table(
            self.client,
            acl_stage=table_stage,
            acl_bind_point_type_list=bpoint_type_list,
            acl_action_type_list=qos_action_type_list,
            field_acl_range_type=acl_range_type,
            field_in_ports=True,
            field_outer_vlan_pri=True)
        self.assertNotEqual(self.qos_acl_table, 0)

        sai_thrift_set_switch_attribute(
            self.client, ingress_acl=self.qos_acl_table)

        group_type = SAI_ACL_TABLE_GROUP_TYPE_PARALLEL
        self.acl_group = sai_thrift_create_acl_table_group(
            self.client,
            acl_stage=table_stage,
            acl_bind_point_type_list=bpoint_type_list,
            type=group_type)
        self.assertNotEqual(self.acl_group, 0)

        self.acl_group_member = sai_thrift_create_acl_table_group_member(
            self.client,
            acl_table_group_id=self.acl_group,
            acl_table_id=self.qos_acl_table)
        self.assertNotEqual(self.acl_group_member, 0)

        #  setup action for catch all entries

        action_tc_set = sai_thrift_acl_action_data_t(
            enable=True,
            parameter=sai_thrift_acl_action_parameter_t(
                u8=7))

        action_color_set = sai_thrift_acl_action_data_t(
            enable=True,
            parameter=sai_thrift_acl_action_parameter_t(
                s32=SAI_PACKET_COLOR_RED))

        in_ports = [self.port24, self.port25, self.port26]
        in_ports_list_t = sai_thrift_acl_field_data_t(
            data=sai_thrift_acl_field_data_data_t(
                objlist=sai_thrift_object_list_t(
                    count=len(in_ports),
                    idlist=in_ports)))

        self.acl_entry = sai_thrift_create_acl_entry(
            self.client,
            table_id=self.qos_acl_table,
            priority=10,
            action_set_tc=action_tc_set,
            action_set_packet_color=action_color_set,
            field_in_ports=in_ports_list_t)

        self.egress_tc_color_list = [
            [0, 0],
            [1, 0],
            [2, 0],
            [3, 0],
            [4, 0],
            [5, 0],
            [6, 0],
            [7, 0],  # green
            [0, 1],
            [1, 1],
            [2, 1],
            [3, 1],
            [4, 1],
            [5, 1],
            [6, 1],
            [7, 1],  # yellow
            [0, 2],
            [1, 2],
            [2, 2],
            [3, 2],
            [4, 2],
            [5, 2],
            [6, 2],
            [7, 2],  # red
        ]

        egress_dscp_list = [
            0, 1, 2, 3, 4, 5, 6, 7,  # mapping green
            8, 9, 10, 11, 12, 13, 14, 15,  # mapping yellow
            16, 17, 18, 19, 20, 21, 22, 23  # mapping red
        ]
        self.tc_color_to_dscp_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
            self.egress_tc_color_list, egress_dscp_list)
        self.assertTrue(self.tc_color_to_dscp_id != 0,
                        "Failed to create qos_map")

        egress_pcp_list = [
            1, 1, 1, 1, 1, 1, 1, 1,  # pcp for green
            2, 2, 2, 2, 2, 2, 2, 2,  # pcp for yellow
            3, 3, 3, 3, 3, 3, 3, 3,  # pcp for red
        ]

        self.tc_color_to_dot1p_id = create_and_verify_qos_map(
            self.client, SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
            self.egress_tc_color_list, egress_pcp_list)
        self.assertTrue(self.tc_color_to_dot1p_id != 0,
                        "Failed to create qos_map")

    def runTest(self):
        try:
            self.negativeTest()
            for port in self.ports:
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dscp_map=self.tc_color_to_dscp_id)
                sai_thrift_set_port_attribute(
                    self.client,
                    port,
                    qos_tc_and_color_to_dot1p_map=self.tc_color_to_dot1p_id)
            self.negativeTest2()
            self.sviRoutingTest()
            self.sviBridgingTest()
        finally:
            pass

    def negativeTest(self):
        """
        Verifies L2 bridging on an SVI port if rmac miss and L2 flooding on
        an SVI if broadcast packet is received before egress map configuration
        """
        print("\nnegativeTest()")

        mac_action = SAI_PACKET_ACTION_FORWARD

        acl_counter = sai_thrift_create_acl_counter(
            self.client, table_id=self.qos_acl_table)

        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=acl_counter),
            enable=True)

        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)

        packets = sai_thrift_get_acl_counter_attribute(
            self.client, acl_counter, packets=True)
        self.assertEqual(packets['packets'], 0)

        pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='11.11.11.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(eth_dst='00:44:22:33:44:55',
                                    eth_src=ROUTER_MAC,
                                    ip_dst='11.11.11.1',
                                    ip_src='192.168.0.1',
                                    ip_id=105,
                                    ip_ttl=63)

        pkt2 = simple_tcp_packet(eth_dst='00:77:66:55:44:44',
                                 eth_src='00:22:22:22:22:22',
                                 ip_dst='11.11.11.1',
                                 ip_src='192.168.0.1',
                                 ip_id=105,
                                 ip_ttl=64,
                                 pktlen=104)

        pkt3 = simple_tcp_packet(eth_dst='FF:FF:FF:FF:FF:FF',
                                 eth_src='00:22:22:22:22:22',
                                 ip_dst='255.255.225.255',
                                 ip_src='192.168.0.1',
                                 ip_id=105,
                                 ip_ttl=64,
                                 pktlen=104)

        try:
            print("Sending packet on port %d to port %d, (192.168.0.1 ---> "
                  "11.11.11.1)  Routed" % (self.dev_port24, self.dev_port10))
            send_packet(self, self.dev_port24, pkt)
            verify_packets(self, exp_pkt, [self.dev_port10])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 1)

            print("Sending packet on port %d to port %d, (192.168.0.1 ---> "
                  "11.11.11.1)  Routed" % (self.dev_port25, self.dev_port10))
            send_packet(self, self.dev_port25, pkt)
            verify_packets(self, exp_pkt, [self.dev_port10])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 2)

            print("Sending packet on port %d to port %d, (192.168.0.1 ---> "
                  "11.11.11.1)  Routed" % (self.dev_port26, self.dev_port10))
            send_packet(self, self.dev_port26, pkt)
            verify_packets(self, exp_pkt, [self.dev_port10])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 3)

            print("Sending packet on port %d, (192.168.0.1 ---> 11.11.11.1) "
                  "flood (missed RMAC)" % (self.dev_port24))
            send_packet(self, self.dev_port24, pkt2)
            verify_packets(self, pkt2, [self.dev_port25, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 4)

            print("Sending packet on port %d, (192.168.0.1 ---> 11.11.11.1) "
                  "flood (missed RMAC)" % (self.dev_port25))
            send_packet(self, self.dev_port25, pkt2)
            verify_packets(self, pkt2, [self.dev_port24, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 5)

            print("Sending packet on port %d, (192.168.0.1 ---> 11.11.11.1) "
                  "flood (missed RMAC)" % (self.dev_port26))
            send_packet(self, self.dev_port26, pkt2)
            verify_packets(self, pkt2, [self.dev_port25, self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 6)

            fdb_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                               mac_address='00:77:66:55:44:44',
                                               bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(self.client,
                                        fdb_entry,
                                        type=SAI_FDB_ENTRY_TYPE_STATIC,
                                        bridge_port_id=self.port24_bp,
                                        packet_action=mac_action)

            print("Sending packet on port %d to port %d, (192.168.0.1 ---> "
                  "11.11.11.1) Routed" % (self.dev_port25, self.dev_port24))
            send_packet(self, self.dev_port25, pkt2)
            verify_packets(self, pkt2, [self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 7)

            print("Sending packet on port %d to port %d, (192.168.0.1 ---> "
                  "11.11.11.1) Routed" % (self.dev_port26, self.dev_port24))
            send_packet(self, self.dev_port26, pkt2)
            verify_packets(self, pkt2, [self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 8)

            print("Sending broadcast packet on port %d, (192.168.0.1 ---> "
                  "255.255.255.255) flood" % (self.dev_port24))
            send_packet(self, self.dev_port24, pkt3)
            verify_packets(self, pkt3, [self.dev_port25, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 9)

            print("Sending broadcast packet on port %d, (192.168.0.1 ---> "
                  "255.255.255.255) flood" % (self.dev_port25))
            send_packet(self, self.dev_port25, pkt3)
            verify_packets(self, pkt3, [self.dev_port24, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 10)

            print("Sending broadcast packet on port %d, (192.168.0.1 ---> "
                  "255.255.255.255) flood" % (self.dev_port26))
            send_packet(self, self.dev_port26, pkt3)
            verify_packets(self, pkt3, [self.dev_port25, self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 11)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_entry)
            action_counter = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=0),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_counter=action_counter)
            sai_thrift_set_acl_counter_attribute(
                self.client, acl_counter, packets=None)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 0)
            sai_thrift_remove_acl_counter(self.client, acl_counter)

    def negativeTest2(self):
        """
        Verifies L2 bridging on an SVI port for port without egress map
        after egress map configuration
        """
        print("\nnegativeTest2()")

        mac_action = SAI_PACKET_ACTION_FORWARD

        port27_bp = sai_thrift_create_bridge_port(
            self.client,
            bridge_id=self.default_1q_bridge,
            port_id=self.port27,
            type=SAI_BRIDGE_PORT_TYPE_PORT,
            admin_state=True)

        vlan_member4 = sai_thrift_create_vlan_member(
            self.client,
            vlan_id=self.vlan100,
            bridge_port_id=port27_bp,
            vlan_tagging_mode=SAI_VLAN_TAGGING_MODE_UNTAGGED)

        sai_thrift_set_port_attribute(
            self.client, self.port27, port_vlan_id=100)

        dmac5 = '00:55:22:33:44:55'

        nhop5 = sai_thrift_create_next_hop(
            self.client,
            ip=sai_ipaddress('10.10.0.5'),
            router_interface_id=self.vlan100_rif,
            type=SAI_NEXT_HOP_TYPE_IP)
        neighbor5 = sai_thrift_neighbor_entry_t(
            rif_id=self.vlan100_rif, ip_address=sai_ipaddress('10.10.0.5'))
        sai_thrift_create_neighbor_entry(
            self.client, neighbor5, dst_mac_address=dmac5)
        route_entry5 = sai_thrift_route_entry_t(
            vr_id=self.default_vrf, destination=sai_ipprefix('10.10.10.5/32'))
        sai_thrift_create_route_entry(
            self.client, route_entry5, next_hop_id=nhop5)

        acl_counter = sai_thrift_create_acl_counter(
            self.client, table_id=self.qos_acl_table)

        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=acl_counter),
            enable=True)

        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)

        packets = sai_thrift_get_acl_counter_attribute(
            self.client, acl_counter, packets=True)
        self.assertEqual(packets['packets'], 0)

        pkt = simple_tcp_packet(eth_dst='00:77:66:55:44:44',
                                eth_src='00:22:22:22:22:22',
                                ip_dst='11.11.11.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64,
                                pktlen=104)

        try:
            fdb_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                               mac_address='00:77:66:55:44:44',
                                               bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(self.client,
                                        fdb_entry,
                                        type=SAI_FDB_ENTRY_TYPE_STATIC,
                                        bridge_port_id=port27_bp,
                                        packet_action=mac_action)

            print("Sending packet on port %d to port %d, (192.168.0.1 ---> "
                  "11.11.11.1) Routed" % (self.dev_port24, self.dev_port27))
            send_packet(self, self.dev_port24, pkt)
            verify_packets(self, pkt, [self.dev_port27])

            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 1)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_entry)
            sai_thrift_remove_route_entry(self.client, route_entry5)
            sai_thrift_remove_neighbor_entry(self.client, neighbor5)
            sai_thrift_remove_next_hop(self.client, nhop5)
            sai_thrift_set_port_attribute(
                self.client, self.port27, port_vlan_id=0)
            sai_thrift_remove_vlan_member(self.client, vlan_member4)
            sai_thrift_remove_bridge_port(self.client, port27_bp)

            action_counter = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=0),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_counter=action_counter)
            sai_thrift_set_acl_counter_attribute(
                self.client, acl_counter, packets=None)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 0)
            sai_thrift_remove_acl_counter(self.client, acl_counter)

    def sviRoutingTest(self):
        """
        Verifies routing on a SVI port with egress mapping
        """
        print("\nsviRoutingTest()")

        try:
            acl_counter = sai_thrift_create_acl_counter(
                self.client, table_id=self.qos_acl_table)

            action_counter = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=acl_counter),
                enable=True)

            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_counter=action_counter)

            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 0)

            pkt = simple_tcp_packet(eth_dst=ROUTER_MAC,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='11.11.11.1',
                                    ip_src='192.168.0.1',
                                    ip_id=105,
                                    ip_ttl=64)
            exp_pkt = simple_tcp_packet(eth_dst='00:44:22:33:44:55',
                                        eth_src=ROUTER_MAC,
                                        ip_dst='11.11.11.1',
                                        ip_src='192.168.0.1',
                                        ip_id=105,
                                        ip_ttl=63,
                                        vlan_pcp=3,
                                        ip_dscp=23)

            print("Sending packet on port %d to port %d, (192.168.0.1 -> "
                  "11.11.11.1) Routed" % (self.dev_port24, self.dev_port10))
            send_packet(self, self.dev_port24, pkt)
            verify_packets(self, exp_pkt, [self.dev_port10])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 1)

            print("Sending packet on port %d to port %d, (192.168.0.1 -> "
                  "11.11.11.1) Routed" % (self.dev_port25, self.dev_port10))
            send_packet(self, self.dev_port25, pkt)
            verify_packets(self, exp_pkt, [self.dev_port10])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 2)

            print("Sending packet on port %d to port %d, (192.168.0.1 -> "
                  "11.11.11.1) Routed" % (self.dev_port26, self.dev_port10))
            send_packet(self, self.dev_port26, pkt)
            verify_packets(self, exp_pkt, [self.dev_port10])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 3)

        finally:
            action_counter = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=0),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_counter=action_counter)
            sai_thrift_set_acl_counter_attribute(
                self.client, acl_counter, packets=None)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 0)
            sai_thrift_remove_acl_counter(self.client, acl_counter)

    def sviBridgingTest(self):
        """
        Verifies L2 bridging on a SVI port if rmac miss and L2 flooding
        on a SVI if broadcast packet is received with egress mapping
        """
        print("\nsviBridgingTest()")

        mac_action = SAI_PACKET_ACTION_FORWARD

        acl_counter = sai_thrift_create_acl_counter(
            self.client, table_id=self.qos_acl_table)

        action_counter = sai_thrift_acl_action_data_t(
            parameter=sai_thrift_acl_action_parameter_t(
                oid=acl_counter),
            enable=True)

        sai_thrift_set_acl_entry_attribute(
            self.client, self.acl_entry,
            action_counter=action_counter)

        pkt2 = simple_tcp_packet(eth_dst='00:77:66:55:44:44',
                                 eth_src='00:22:22:22:22:22',
                                 ip_dst='11.11.11.1',
                                 ip_src='192.168.0.1',
                                 ip_id=105,
                                 ip_ttl=64,
                                 pktlen=104)
        exp_pkt2 = simple_tcp_packet(eth_dst='00:77:66:55:44:44',
                                     eth_src='00:22:22:22:22:22',
                                     ip_dst='11.11.11.1',
                                     ip_src='192.168.0.1',
                                     ip_id=105,
                                     ip_ttl=64,
                                     pktlen=104,
                                     vlan_pcp=2,
                                     ip_dscp=11)
        pkt3 = simple_tcp_packet(eth_dst='FF:FF:FF:FF:FF:FF',
                                 eth_src='00:22:22:22:22:22',
                                 ip_dst='255.255.225.255',
                                 ip_src='192.168.0.1',
                                 ip_id=105,
                                 ip_ttl=64,
                                 pktlen=104)
        exp_pkt3 = simple_tcp_packet(eth_dst='FF:FF:FF:FF:FF:FF',
                                     eth_src='00:22:22:22:22:22',
                                     ip_dst='255.255.225.255',
                                     ip_src='192.168.0.1',
                                     ip_id=105,
                                     ip_ttl=64,
                                     pktlen=104,
                                     vlan_pcp=1,
                                     ip_dscp=5)

        try:
            action_tc_set = sai_thrift_acl_action_data_t(
                enable=True,
                parameter=sai_thrift_acl_action_parameter_t(
                    u8=3))
            action_color_set = sai_thrift_acl_action_data_t(
                enable=True,
                parameter=sai_thrift_acl_action_parameter_t(
                    s32=SAI_PACKET_COLOR_YELLOW))

            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_set_tc=action_tc_set)
            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_set_packet_color=action_color_set)

            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 0)

            print("Sending packet on port %d, (192.168.0.1 -> 11.11.11.1) "
                  "flood (missed RMAC)" % (self.dev_port24))
            send_packet(self, self.dev_port24, pkt2)
            verify_packets(self, exp_pkt2, [self.dev_port25, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 1)

            print("Sending packet on port %d, (192.168.0.1 -> 11.11.11.1) "
                  "flood (missed RMAC)" % (self.dev_port25))
            send_packet(self, self.dev_port25, pkt2)
            verify_packets(self, exp_pkt2, [self.dev_port24, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 2)

            print("Sending packet on port %d, (192.168.0.1 -> 11.11.11.1) "
                  "flood (missed RMAC)" % (self.dev_port26))
            send_packet(self, self.dev_port26, pkt2)
            verify_packets(self, exp_pkt2, [self.dev_port25, self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 3)

            fdb_entry = sai_thrift_fdb_entry_t(switch_id=self.switch_id,
                                               mac_address='00:77:66:55:44:44',
                                               bv_id=self.vlan100)
            sai_thrift_create_fdb_entry(self.client,
                                        fdb_entry,
                                        type=SAI_FDB_ENTRY_TYPE_STATIC,
                                        bridge_port_id=self.port24_bp,
                                        packet_action=mac_action)

            print("Sending packet on port %d to port %d, (192.168.0.1 -> "
                  "11.11.11.1) Routed" % (self.dev_port25, self.dev_port24))
            send_packet(self, self.dev_port25, pkt2)
            verify_packets(self, exp_pkt2, [self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 4)

            print("Sending packet on port %d to port %d, (192.168.0.1 -> "
                  "11.11.11.1) Routed" % (self.dev_port26, self.dev_port24))
            send_packet(self, self.dev_port26, pkt2)
            verify_packets(self, exp_pkt2, [self.dev_port24])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 5)

            action_tc_set = sai_thrift_acl_action_data_t(
                enable=True,
                parameter=sai_thrift_acl_action_parameter_t(
                    u8=5))
            action_color_set = sai_thrift_acl_action_data_t(
                enable=True,
                parameter=sai_thrift_acl_action_parameter_t(
                    s32=SAI_PACKET_COLOR_GREEN))

            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_set_tc=action_tc_set)
            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_set_packet_color=action_color_set)

            print("Sending broadcast packet on port %d, (192.168.0.1 -> "
                  "255.255.255.255) flood" % (self.dev_port24))
            send_packet(self, self.dev_port24, pkt3)
            verify_packets(self, exp_pkt3, [self.dev_port25, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 1)

            print("Sending broadcast packet on port %d, (192.168.0.1 -> "
                  "255.255.255.255) flood" % (self.dev_port25))
            send_packet(self, self.dev_port25, pkt3)
            verify_packets(self, exp_pkt3, [self.dev_port24, self.dev_port26])
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 2)

            print("Sending broadcast packet on port %d, (192.168.0.1 -> "
                  "255.255.255.255) flood" % (self.dev_port26))
            send_packet(self, self.dev_port26, pkt3)
            verify_packets(self, exp_pkt3, [self.dev_port25, self.dev_port24])

            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 3)

        finally:
            sai_thrift_remove_fdb_entry(self.client, fdb_entry)
            action_counter = sai_thrift_acl_action_data_t(
                parameter=sai_thrift_acl_action_parameter_t(
                    oid=0),
                enable=True)
            sai_thrift_set_acl_entry_attribute(
                self.client, self.acl_entry,
                action_counter=action_counter)
            sai_thrift_set_acl_counter_attribute(
                self.client, acl_counter, packets=None)
            packets = sai_thrift_get_acl_counter_attribute(
                self.client, acl_counter, packets=True)
            self.assertEqual(packets['packets'], 0)
            sai_thrift_remove_acl_counter(self.client, acl_counter)

    def tearDown(self):
        sai_thrift_set_switch_attribute(self.client, ingress_acl=0)
        sai_thrift_remove_acl_entry(self.client, self.acl_entry)
        sai_thrift_remove_acl_table_group_member(
            self.client, self.acl_group_member)
        sai_thrift_remove_acl_table(self.client, self.qos_acl_table)
        sai_thrift_remove_acl_table_group(self.client, self.acl_group)

        for port in self.ports:
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_and_color_to_dscp_map=0)
            sai_thrift_set_port_attribute(
                self.client,
                port,
                qos_tc_and_color_to_dot1p_map=0)

        sai_thrift_remove_qos_map(
            self.client, self.tc_color_to_dscp_id)
        sai_thrift_remove_qos_map(
            self.client, self.tc_color_to_dot1p_id)

        sai_thrift_remove_route_entry(self.client, self.route_entry1)
        sai_thrift_remove_route_entry(self.client, self.route_entry2)
        sai_thrift_remove_route_entry(self.client, self.route_entry3)
        sai_thrift_remove_route_entry(self.client, self.route_entry4)

        sai_thrift_remove_neighbor_entry(self.client, self.neighbor1)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor2)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor3)
        sai_thrift_remove_neighbor_entry(self.client, self.neighbor4)

        sai_thrift_remove_next_hop(self.client, self.nhop1)
        sai_thrift_remove_next_hop(self.client, self.nhop2)
        sai_thrift_remove_next_hop(self.client, self.nhop3)
        sai_thrift_remove_next_hop(self.client, self.nhop4)

        sai_thrift_remove_router_interface(self.client, self.vlan100_rif)

        sai_thrift_set_port_attribute(self.client, self.port24, port_vlan_id=0)
        sai_thrift_set_port_attribute(self.client, self.port25, port_vlan_id=0)
        sai_thrift_set_port_attribute(self.client, self.port26, port_vlan_id=0)

        sai_thrift_remove_vlan_member(self.client, self.vlan_member1)
        sai_thrift_remove_vlan_member(self.client, self.vlan_member2)
        sai_thrift_remove_vlan_member(self.client, self.vlan_member3)

        sai_thrift_remove_vlan(self.client, self.vlan100)

        sai_thrift_remove_bridge_port(self.client, self.port24_bp)
        sai_thrift_remove_bridge_port(self.client, self.port25_bp)
        sai_thrift_remove_bridge_port(self.client, self.port26_bp)

        super(EgressPcpDscpMapSviTest, self).tearDown()

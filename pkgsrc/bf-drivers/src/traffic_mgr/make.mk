###############################################################################
#
# 
#
###############################################################################

LIBRARY := traffic_mgr
$(LIBRARY)_SUBDIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(BUILDER)/lib.mk

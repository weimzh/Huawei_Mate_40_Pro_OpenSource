obj-$(CONFIG_DUAL_ROLE_USB_INTF)	+= tcpci_dual_role.o

obj-$(CONFIG_HISI_TCPC)			+= tcpci_core.o tcpci_typec.o tcpci_alert.o tcpci_timer.o tcpm.o

obj-$(CONFIG_HISI_TCPC_HI6526)		+= hi6526.o hisi-tcpc.o hisi_usb_vbus.o

obj-$(CONFIG_USB_POWER_DELIVERY_SUPPORT)        += tcpci_event.o \
                                pd_core.o pd_policy_engine.o pd_process_evt.o \
                                pd_dpm_core.o pd_dpm_alt_mode_dp.o\
                                pd_process_evt_snk.o pd_process_evt_src.o pd_process_evt_vdm.o \
                                pd_process_evt_drs.o pd_process_evt_prs.o pd_process_evt_vcs.o \
                                pd_process_evt_dbg.o \
                                pd_policy_engine_src.o pd_policy_engine_snk.o pd_policy_engine_ufp.o pd_policy_engine_vcs.o \
                                pd_policy_engine_dfp.o pd_policy_engine_dr.o pd_policy_engine_drs.o pd_policy_engine_prs.o \
                                pd_policy_engine_dbg.o

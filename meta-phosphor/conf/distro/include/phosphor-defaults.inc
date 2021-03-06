OBMC_BMC_INSTANCES ?= "0"
OBMC_CHASSIS_INSTANCES ?= "0"
OBMC_CHECKSTOP_INSTANCES ?= "0"
OBMC_FAN_INSTANCES ?= ""
OBMC_HOST_INSTANCES ?= "0"
OBMC_POWER_BUTTON_INSTANCES ?= "0"
OBMC_POWER_INSTANCES ?= "0"
OBMC_RESET_BUTTON_INSTANCES ?= "0"
OBMC_WATCHDOG_INSTANCES ?= "0"

PREFERRED_PROVIDER_virtual/obmc-chassis-mgmt ?= "obmc-phosphor-chassisd"
PREFERRED_PROVIDER_virtual/obmc-event-mgmt ?= "obmc-phosphor-event"
PREFERRED_PROVIDER_virtual/obmc-fan-mgmt ?= "obmc-phosphor-fand"
PREFERRED_PROVIDER_virtual/obmc-flash-mgmt ?= "obmc-phosphor-flashd"
PREFERRED_PROVIDER_virtual/obmc-host-ipmi-hw ?= "phosphor-ipmi-hw-example"

# obmc-bmc-state-manager
#
# Provides an implementation of the xyz.openbmc_project.State.BMC
# interface.
VIRTUAL-RUNTIME_obmc-bmc-state-manager ?= "phosphor-state-manager-bmc"

# obmc-chassis-state-manager
#
# Provides an implementation of the xyz.openbmc_project.State.Chassis
# interface.
VIRTUAL-RUNTIME_obmc-chassis-state-manager ?= "phosphor-state-manager-chassis"

# obmc-host-state-manager
#
# Provides an implementation of the xyz.openbmc_project.State.Host
# interface.
VIRTUAL-RUNTIME_obmc-host-state-manager ?= "phosphor-state-manager-host"

# obmc-inventory-manager
#
# Provides an implementation of the xyz.openbmc_project.Inventory.Manager
# interface.
VIRTUAL-RUNTIME_obmc-inventory-manager ?= "phosphor-inventory-manager"

# obmc-led-manager
#
# Provides an implementation of the xyz.openbmc_project.ledmanager interface.
VIRTUAL-RUNTIME_obmc-leds-manager ?= "phosphor-led-manager"

# obmc-led-sysfs
#
# Provides an implementation of xyz.openbmc_project.Led.Physical for
# Linux kernel LED subsystem LEDs.
VIRTUAL-RUNTIME_obmc-leds-sysfs ?= "phosphor-led-sysfs"

# obmc-bmc-code-mgr
#
# Provides an implementation of the xyz.openbmc_project.Software.BMC.Version
# interface.
VIRTUAL-RUNTIME_obmc-bmc-code-mgr ?= "phosphor-software-manager-version"

PREFERRED_PROVIDER_virtual/obmc-logging-mgmt ?= "phosphor-logging"
PREFERRED_PROVIDER_virtual/obmc-net-ipmi ?= "phosphor-net-ipmid"

# obmc-sensors-hwmon
#
# Provides an implementation of xyz.openbmc_project.Sensor.Value
# for hwmon sensors.
VIRTUAL-RUNTIME_obmc-sensors-hwmon ?= "phosphor-hwmon"

PREFERRED_PROVIDER_virtual/obmc-settings-mgmt ?= "phosphor-settings"
PREFERRED_PROVIDER_virtual/obmc-system-mgmt ?= "obmc-phosphor-sysd"
PREFERRED_PROVIDER_virtual/obmc-user-mgmt ?= "obmc-phosphor-user"
PREFERRED_PROVIDER_virtual/obmc-wsgihost ?= "phosphor-gevent"

# phosphor-hwmon-config
#
# The phosphor-hwmon package can have its configuration generated
# automatically if the MRW feature is enabled.
VIRTUAL-RUNTIME_phosphor-hwmon-config ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-hwmon-config-mrw')}"

# virtual/phosphor-ipmi-fru-hostfw-config
#
# The phosphor-ipmi-fru application is data-driven and requires an input
# mapping of how the host firmware reports inventory via IPMI.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-ipmi-fru build process.
PREFERRED_PROVIDER_virtual/phosphor-ipmi-fru-hostfw-config ?= "phosphor-ipmi-fru-hostfw-config-example-native"

# The phosphor-ipmi-fru application is data-driven and requires an input
# mapping of IPMI inventory metadata to DBus objects interfaces and properties.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-ipmi-fru build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-ipmi-fru-inventory ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-ipmi-fru-inventory-mrw-native', 'phosphor-ipmi-fru-inventory-example-native')}"
PREFERRED_PROVIDER_virtual/phosphor-ipmi-fru-properties ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-ipmi-fru-properties-mrw-native', 'phosphor-ipmi-fru-properties-example-native')}"

# The phosphor-led-manager application is data-driven and requires an input
# yaml of LED group and members.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-led-manager build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-led-manager-config-native ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-led-manager-config-mrw-native', 'phosphor-led-manager-config-example-native')}"

OBMC_DBUS_PATH_ROOT ?= "/xyz/openbmc_project"
OBMC_DBUS_IFACE_ROOT ?= "xyz.openbmc_project"

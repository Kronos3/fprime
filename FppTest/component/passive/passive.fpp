#include "../include/fpp_types.fppi"
#include "../include/port_types.fppi"
#include "../include/port_index_enums.fppi"

@ A passive component
passive component PassiveTest {

  import FppTest.SerialPorts
  import FppTest.SpecialPorts
  import FppTest.TypedPorts

  include "../include/commands.fppi"
  include "../include/events.fppi"
  include "../include/telemetry.fppi"
  include "../include/params.fppi"
  include "../include/external_params.fppi"

}

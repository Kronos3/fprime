module FppTest {

  @ A struct with a fixed-size member array
  struct FixedSizeData {
    data: [1024] F32
  }

  active component Comp {

    import SpecialPorts

    async command Command(
        a: U32,
        b: F32,
        c: string size 10
    )

    event Event(
        a: U32,
        b: U32,
        c: U32
    ) severity activity high format "a: {}, b: {}, c: {}"

    telemetry Telemetry: U32

    @ A record containing fixed-size data
    product record FixedSizeDataRecord: FixedSizeData id 0x00
    @ A record containing a variable-size array
    product record F32ArrayRecord: F32 array id 0x01

    product container Product

  }

}

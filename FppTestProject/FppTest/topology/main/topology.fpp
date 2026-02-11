module FppTest {

  topology Receiver {
    instance receiver1
    instance receiver2
  }

  topology Special {
    instance framework
    instance comp

    command connections instance framework
    event connections instance framework
    health connections instance framework
    param connections instance framework
    telemetry connections instance framework
    text event connections instance framework
    time connections instance framework

    connections CompFramework {

    }
  }

  topology FppTest {

    import Sync
    import Guarded
    import Async
    import Special

  }

}

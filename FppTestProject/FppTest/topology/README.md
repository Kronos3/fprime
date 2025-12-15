# FppTest Topology

The `FppTest` topology is an integration-style test
which connects components together to test the
Fpp codegen for topology connections.

There are two sets of components to implement a
comprehensive set of tests:

- Sender/Receiver
- Comp/Framework

## Sender/Receiver

The sender/receiver topologies will test typed/serial
ports using a ping-pong style of port calling.

The sender will invoke an output port to the receiver
and the receiver will collect up information sent by
the sender and reply to the sender. The sender will
then validate the response from the receiver and
pass/fail the test.

## Comp/Framework

The comp/framework is a simple topology meant to
test special ports. `Comp` is a component 
meant to mimic a typical FPrime component though
with support for all the special features like
commands, telemetry, data products, events, and
parameters.

The `Framework` component is responsible for handling
and feeding the Tester with what the Fprime framework
would normally handle. It is also responsible for
driving the tests.

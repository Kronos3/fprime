// ======================================================================
// \title  PassiveTest.hpp
// \author tiffany
// \brief  hpp file for PassiveTest component implementation class
// ======================================================================

#ifndef PassiveTest_HPP
#define PassiveTest_HPP

#include "FppTest/component/passive/PassiveTestComponentAc.hpp"
#include "FppTest/component/types/FormalParamTypes.hpp"


class PassiveTest :
  public PassiveTestComponentBase
{

  public:

    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct PassiveTest object
    PassiveTest(
        const char* const compName //!< The component name
    );

    //! Destroy PassiveTest object
    ~PassiveTest();

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for user-defined typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for arrayArgsGuarded
    void arrayArgsGuarded_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamArray& a, //!< An array
        FormalParamArray& aRef //!< An array ref
    ) override;

    //! Handler implementation for arrayArgsSync
    void arrayArgsSync_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamArray& a, //!< An array
        FormalParamArray& aRef //!< An array ref
    ) override;

    //! Handler implementation for arrayReturnGuarded
    FormalParamArray arrayReturnGuarded_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamArray& a, //!< An array
        FormalParamArray& aRef //!< An array ref
    ) override;

    //! Handler implementation for arrayReturnSync
    FormalParamArray arrayReturnSync_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamArray& a, //!< An array
        FormalParamArray& aRef //!< An array ref
    ) override;

    //! Handler implementation for enumArgsGuarded
    void enumArgsGuarded_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamEnum& en, //!< An enum
        FormalParamEnum& enRef //!< An enum ref
    ) override;

    //! Handler implementation for enumArgsSync
    void enumArgsSync_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamEnum& en, //!< An enum
        FormalParamEnum& enRef //!< An enum ref
    ) override;

    //! Handler implementation for enumReturnGuarded
    FormalParamEnum enumReturnGuarded_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamEnum& en, //!< An enum
        FormalParamEnum& enRef //!< An enum ref
    ) override;

    //! Handler implementation for enumReturnSync
    FormalParamEnum enumReturnSync_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamEnum& en, //!< An enum
        FormalParamEnum& enRef //!< An enum ref
    ) override;

    //! Handler implementation for stringReturnGuarded
    Fw::String stringReturnGuarded_handler(
        FwIndexType portNum,          //!< The port number
        const Fw::StringBase& str,    //!< A string
        Fw::StringBase& strRef        //!< A string ref
    ) override;

    //! Handler implementation for stringReturnSync
    Fw::String stringReturnSync_handler(
        FwIndexType portNum,          //!< The port number
        const Fw::StringBase& str,    //!< A string
        Fw::StringBase& strRef        //!< A string ref
    ) override;


    //! Handler implementation for noArgsGuarded
    void noArgsGuarded_handler(
        FwIndexType portNum //!< The port number
    ) override;

    //! Handler implementation for noArgsReturnGuarded
    bool noArgsReturnGuarded_handler(
        FwIndexType portNum //!< The port number
    ) override;

    //! Handler implementation for noArgsReturnSync
    bool noArgsReturnSync_handler(
        FwIndexType portNum //!< The port number
    ) override;

    //! Handler implementation for noArgsSync
    void noArgsSync_handler(
        FwIndexType portNum //!< The port number
    ) override;

    //! Handler implementation for primitiveArgsGuarded
    void primitiveArgsGuarded_handler(
        FwIndexType portNum, //!< The port number
        U32 u32,
        U32& u32Ref,
        F32 f32,
        F32& f32Ref,
        bool b,
        bool& bRef
    ) override;

    //! Handler implementation for primitiveArgsSync
    void primitiveArgsSync_handler(
        FwIndexType portNum, //!< The port number
        U32 u32,
        U32& u32Ref,
        F32 f32,
        F32& f32Ref,
        bool b,
        bool& bRef
    ) override;

    //! Handler implementation for primitiveReturnGuarded
    U32 primitiveReturnGuarded_handler(
        FwIndexType portNum, //!< The port number
        U32 u32,
        U32& u32Ref,
        F32 f32,
        F32& f32Ref,
        bool b,
        bool& bRef
    ) override;

    //! Handler implementation for primitiveReturnSync
    U32 primitiveReturnSync_handler(
        FwIndexType portNum, //!< The port number
        U32 u32,
        U32& u32Ref,
        F32 f32,
        F32& f32Ref,
        bool b,
        bool& bRef
    ) override;

    //! Handler implementation for stringArgsGuarded
    void stringArgsGuarded_handler(
        FwIndexType portNum, //!< The port number
        const Fw::StringBase& str80, //!< A string of size 80
        Fw::StringBase& str80Ref,
        const Fw::StringBase& str100, //!< A string of size 100
        Fw::StringBase& str100Ref
    ) override;

    //! Handler implementation for stringArgsSync
    void stringArgsSync_handler(
        FwIndexType portNum, //!< The port number
        const Fw::StringBase& str80, //!< A string of size 80
        Fw::StringBase& str80Ref,
        const Fw::StringBase& str100, //!< A string of size 100
        Fw::StringBase& str100Ref
    ) override;

    //! Handler implementation for structArgsGuarded
    void structArgsGuarded_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamStruct& s, //!< A struct
        FormalParamStruct& sRef //!< A struct ref
    ) override;

    //! Handler implementation for structArgsSync
    void structArgsSync_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamStruct& s, //!< A struct
        FormalParamStruct& sRef //!< A struct ref
    ) override;

    //! Handler implementation for structReturnGuarded
    FormalParamStruct structReturnGuarded_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamStruct& s, //!< A struct
        FormalParamStruct& sRef //!< A struct ref
    ) override;

    //! Handler implementation for structReturnSync
    FormalParamStruct structReturnSync_handler(
        FwIndexType portNum, //!< The port number
        const FormalParamStruct& s, //!< A struct
        FormalParamStruct& sRef //!< A struct ref
    ) override;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for user-defined serial input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for serialGuarded
    void serialGuarded_handler(
        FwIndexType portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    ) override;

    //! Handler implementation for serialSync
    void serialSync_handler(
        FwIndexType portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    ) override;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command CMD_NO_ARGS
    void CMD_NO_ARGS_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    ) override;

    //! Handler implementation for command CMD_PRIMITIVE
    void CMD_PRIMITIVE_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32_1, //!< A U32
        U32 u32_2, //!< A U32
        F32 f32_1, //!< An F32
        F32 f32_2, //!< An F32
        bool b1, //!< A boolean
        bool b2 //!< A boolean
    ) override;

    //! Handler implementation for command CMD_STRINGS
    void CMD_STRINGS_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        const Fw::CmdStringArg& str1, //!< A string
        const Fw::CmdStringArg& str2 //!< Another string
    ) override;

    //! Handler implementation for command CMD_ENUM
    void CMD_ENUM_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        FormalParamEnum en //!< An enum
    ) override;

    //! Handler implementation for command CMD_ARRAY
    void CMD_ARRAY_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        FormalParamArray arr //!< An array
    ) override;

    //! Handler implementation for command CMD_STRUCT
    void CMD_STRUCT_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        FormalParamStruct str //!< A struct
    ) override;

  public:

    //! Enables checking the serialization status of serial port invocations
    Fw::SerializeStatus serializeStatus;

    // Command test values
    FppTest::Types::PrimitiveParams primitiveCmd;
    FppTest::Types::CmdStringParams stringCmd;
    FppTest::Types::EnumParam enumCmd;
    FppTest::Types::ArrayParam arrayCmd;
    FppTest::Types::StructParam structCmd;

};


#endif

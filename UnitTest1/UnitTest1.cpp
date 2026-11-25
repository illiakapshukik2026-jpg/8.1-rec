#include "pch.h"
#include "CppUnitTest.h"
#define UNIT_TEST
#include "../8.1 rec/8.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81Rec
{
    TEST_CLASS(UnitTest81Rec)
    {
    public:
        TEST_METHOD(HasSQPairTest)
        {
            Assert::IsTrue(HasSQPairRec("abSQcd"));
            Assert::IsTrue(HasSQPairRec("xQSy"));
            Assert::IsFalse(HasSQPairRec("SxQ"));
            Assert::IsFalse(HasSQPairRec("sq QQ SS"));
            Assert::IsFalse(HasSQPairRec(""));
        }

        TEST_METHOD(ReplaceSQPairsTest)
        {
            Assert::AreEqual(string("A***B***C"), ReplaceSQPairsRec("ASQBQSC"));
            Assert::AreEqual(string("***S"), ReplaceSQPairsRec("SQS"));
            Assert::AreEqual(string("S***"), ReplaceSQPairsRec("SSQ"));
            Assert::AreEqual(string("abc SS"), ReplaceSQPairsRec("abc SS"));
            Assert::AreEqual(string(""), ReplaceSQPairsRec(""));
        }
    };
}


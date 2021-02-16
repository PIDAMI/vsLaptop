#include "pch.h"
#include "Set.h"



TEST(SetAdd, AddFirstElem) {
	Set<std::string> s;
	EXPECT_EQ(s.Add("qwe"), 1);

}


TEST(SetAdd, AddToEnd) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("bcd");
	int pos = 3;
	EXPECT_EQ(s.Add("zzz"), pos);

}
TEST(SetAdd, AddInMiddle) {
	Set<std::string> s;
	int head_pos = s.Add("abc");
	int tail_pos = s.Add("zzz");
	int pos = s.Add("bcd");
	EXPECT_EQ(pos,2);

}


TEST(SetDel, DelLastElemReturnValidVal) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("bcd");
	int old_power = s.Power();
	int result = s.Del("bcd");
	int new_power = s.Power();
	EXPECT_TRUE(result >= 0);
	EXPECT_FALSE(s.Check("bcd"));
	EXPECT_EQ(new_power, old_power - 1);
}
TEST(SetDel, DelMidElemReturnValidVal) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("bcd");
	s.Add("zxc");
	int old_power = s.Power();
	int result = s.Del("bcd");	
	int new_power = s.Power();

	EXPECT_TRUE(result >= 0);
	EXPECT_FALSE(s.Check("bcd"));
	EXPECT_EQ(new_power, old_power - 1);
}

TEST(SetDel, DelHeadReturnValidVal) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("bcd");
	int old_power = s.Power();
	int result = s.Del("abc");	
	int new_power = s.Power();

	EXPECT_TRUE(result >= 0);
	EXPECT_FALSE(s.Check("abc"));
	EXPECT_EQ(new_power, old_power - 1);

}

TEST(SetDel, DelOnlyElemValidVal) {
	Set<std::string> s;
	s.Add("abc");
	int result = s.Del("abc");
	int new_power = s.Power();
	EXPECT_TRUE(result >= 0);
	EXPECT_FALSE(s.Check("abc"));
	EXPECT_EQ(0, new_power);
	

}


TEST(SetPower, EmptySetReturnZero) {
	Set<std::string> s;
	EXPECT_EQ(0, s.Power());
}

TEST(SetPower, NonEmptySetReturnValidVal) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("abc");
	int size = 2;
	EXPECT_EQ(size, s.Power());
}

TEST(SetIncludes, NoCommonElementsReturnFalse) {
	Set<std::string> s;
	s.Add("asd");
	s.Add("bcd");
	Set<std::string> q;
	q.Add("zxc");
	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, IncludeItselfReturnTrue) {
	Set<std::string> s;
	s.Add("asd");
	s.Add("bcd");
	s.Add("zxc");
	s.Add("dde");
	EXPECT_TRUE(s.Includes(s));
}

TEST(SetIncludes, EmptySetAsParamReturnTrue) {
	Set<std::string> s;
	s.Add("asd");
	s.Add("bcd");
	Set<std::string> q;
	EXPECT_TRUE(s.Includes(q));
}
TEST(SetIncludes, BothEmptySetsReturnTrue) {
	Set<std::string> s;
	Set<std::string> q;
	EXPECT_TRUE(s.Includes(q));
}
TEST(SetIncludes, MainSetEmptyReturnFalse) {
	Set<std::string> s;
	Set<std::string> q;
	q.Add("asd");
	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, EqualPowerAndHaveSomeCommonElemsReturnFalse) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("xdd");
	
	Set<std::string> q;
	q.Add("asd");
	q.Add("wes");

	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, SecondSetBiggerReturnFalse) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("xdd");

	Set<std::string> q;
	q.Add("asd");
	q.Add("wes");
	q.Add("ccx");
	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, IncludesReturnTrue) {
	Set<std::string> s;
	s.Add("abc");
	s.Add("xdd");
	s.Add("zxc");
	Set<std::string> q;
	q.Add("abc");
	EXPECT_TRUE(s.Includes(q));
}

TEST(SetIncludes, EqualSetsReturnTrue) {
	Set<std::string> s;
	s.Add("xdd");
	s.Add("abc");
	s.Add("zxc");
	Set<std::string> q;
	q.Add("abc");
	q.Add("zxc");
	q.Add("xdd");

	EXPECT_TRUE(s.Includes(q));
}



TEST(SetUnion, EmptySetsReturnEmptySet) {
	Set<std::string> s;
	Set<std::string> q;
	Set<std::string> result = s.Union(q);
	EXPECT_EQ(result.Power(),0);
}

TEST(SetUnion, UnionItselfReturnValidVal) {
	Set<std::string> s;

	s.Add("xdd");
	s.Add("abc");
	s.Add("zxc");
	Set<std::string> result = s.Union(s);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));
}

TEST(SetUnion, FirstSetEmptyReturnSecond) {
	Set<std::string> s;
	Set<std::string> q;
	q.Add("bcv");
	q.Add("asd");


	Set<std::string> result = s.Union(q);
	EXPECT_EQ(result.Power(), q.Power());
	EXPECT_TRUE(result.Includes(q));
	EXPECT_TRUE(q.Includes(result));
}


TEST(SetUnion, SecondSetEmptyReturnFirst) {
	Set<std::string> s;
	Set<std::string> q;
	s.Add("bcv");
	s.Add("asd");


	Set<std::string> result = s.Union(q);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));

}

TEST(SetUnion, EqualSetsReturnValidVal) {
	Set<std::string> s;

	s.Add("bcv");
	s.Add("asd");
	Set<std::string> q;
	q.Add("bcv");
	q.Add("asd");

	Set<std::string> result = s.Union(q);
	EXPECT_EQ(result.Power(), s.Power());

	EXPECT_TRUE(result.Includes(q));
	EXPECT_TRUE(q.Includes(result));

	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));

}

TEST(SetUnion, CommonElemsReturnValidVal) {
	Set<std::string> s;

	s.Add("bcv");
	s.Add("asd");
	Set<std::string> q;
	q.Add("asd");
	q.Add("ok");
	q.Add("wwe");

	Set<std::string> result = s.Union(q);
	EXPECT_EQ(result.Power(), s.Power()+q.Power()-1);

	EXPECT_TRUE(result.Includes(q));

	EXPECT_TRUE(result.Includes(s));

}

TEST(SetIntersection, EmptySetsReturnEmpty) {
	Set<std::string> s;
	Set<std::string> q;
	Set<std::string> result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 0);
}

TEST(SetIntersection, IntersectItselfReturnValidVal) {
	Set<std::string> s;

	s.Add("bcv");
	s.Add("asd");
	Set<std::string> result = s.Intersection(s);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Includes(s));

	EXPECT_TRUE(s.Includes(result));
}


TEST(SetIntersection, MainSetEmptyReturnEmpty) {
	Set<std::string> s;
	Set<std::string> q;
	q.Add("asd");
	q.Add("bcd");
	Set<std::string> result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_FALSE(result.Check("bcd"));
}

TEST(SetIntersection, SecondSetEmptyReturnEmpty) {
	Set<std::string> s;
	Set<std::string> q;
	s.Add("asd");
	s.Add("bcd");
	Set<std::string> result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_FALSE(result.Check("bcd"));
}


TEST(SetIntersection, HaveCommonElemsReturnValidVal) {
	Set<std::string> s;
	s.Add("asd");//
	s.Add("bcd");
	s.Add("zxc");//
	s.Add("ttt");
	Set<std::string> q;
	q.Add("asd");//
	q.Add("zxc");//
	q.Add("qwe");
	q.Add("rty");
	Set<std::string> result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 2);
	EXPECT_TRUE(result.Check("asd"));
	EXPECT_TRUE(result.Check("zxc"));
	EXPECT_FALSE(result.Check("ttt"));
}

TEST(SetSubtract, BothEmptyReturnEmpty) {
	Set<std::string> s;
	Set<std::string> q;
	Set<std::string> result = s.Subtract(q);
	EXPECT_EQ(s.Power(), 0);


}
TEST(SetSubtract, MainSetEmptyReturnEmpty) {
	Set<std::string> s;
	Set<std::string> q;
	q.Add("qwe");
	q.Add("asd");
	Set<std::string> result = s.Subtract(q);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Check("qwe"));
	EXPECT_FALSE(result.Check("asd"));

}

TEST(SetSubtract, SecondSetEmptyReturnFirstSet) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");
	Set<std::string> q;
	Set<std::string> result = s.Subtract(q);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Check("qwe"));
	EXPECT_TRUE(result.Check("asd"));

}


TEST(SetSubtract, SubtractItselfReturnEmpty) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	s.Add("ddw");

	Set<std::string> result = s.Subtract(s);
	EXPECT_EQ(result.Power(), 0);
}

TEST(SetSubtract, SomeCommonElemsfReturnValidVal) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");//
	s.Add("zxc");
	s.Add("ddw");//

	Set<std::string> q;
	q.Add("ddw");//
	q.Add("asd");//
	q.Add("mnv");
	q.Add("yuu");


	Set<std::string> result = s.Subtract(q);
	EXPECT_EQ(result.Power(), s.Power()-s.Intersection(q).Power());
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_FALSE(result.Check("ddw"));

}

TEST(SetXOR, EmptySetsReturnEmpty) {
	Set<std::string> s;
	Set<std::string> q;
	Set<std::string> result = s.XOR(q);
	EXPECT_EQ(result.Power(), 0);

}


TEST(SetXOR, OneSetEmptyReturnValidVal) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	Set<std::string> q;
	Set<std::string> result = s.XOR(q);
	EXPECT_EQ(result.Power(), s.Power());

	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));

}

TEST(SetXOR, XORItselfReturnEmpty) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	Set<std::string> result = s.XOR(s);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Includes(s));

}


TEST(SetXOR, NoCommonElemsReturnUnion) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	Set<std::string> q;
	q.Add("ghj");
	q.Add("llk");
	Set<std::string> result = s.XOR(q);
	Set<std::string> _union;
	_union.Add("qwe");
	_union.Add("asd");
	_union.Add("zxc");
	_union.Add("ghj");
	_union.Add("llk");
	EXPECT_EQ(result.Power(), _union.Power());
	EXPECT_TRUE(result.Includes(_union));
	EXPECT_TRUE(_union.Includes(result));


}

TEST(SetXOR, SomeCommonElemsReturnValidVal) {
	Set<std::string> s;
	s.Add("qwe");
	s.Add("asd");//
	s.Add("zxc");
	Set<std::string> q;
	q.Add("ghj");
	q.Add("asd");//
	Set<std::string> xor;
	xor.Add("qwe");
	xor.Add("zxc");
	xor.Add("ghj");
	Set<std::string> result = s.XOR(q);
	EXPECT_EQ(result.Power(), xor .Power());
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_TRUE(result.Includes(xor));
	EXPECT_TRUE(xor.Includes(result));

}




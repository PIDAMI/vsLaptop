#include "pch.h"
#include "Set.h"



TEST(SetAdd, AddFirstElem) {
	Set s;
	EXPECT_EQ(s.Add("qwe"), 1);

}


TEST(SetAdd, AddToEnd) {
	Set s;
	s.Add("abc");
	s.Add("bcd");
	int pos = 3;
	EXPECT_EQ(s.Add("zzz"), pos);

}
TEST(SetAdd, AddInMiddle) {
	Set s;
	int head_pos = s.Add("abc");
	int tail_pos = s.Add("zzz");
	int pos = s.Add("bcd");
	EXPECT_EQ(pos,2);

}


TEST(SetDel, DelLastElemReturnValidVal) {
	Set s;
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
	Set s;
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
	Set s;
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
	Set s;
	s.Add("abc");
	int result = s.Del("abc");
	int new_power = s.Power();
	EXPECT_TRUE(result >= 0);
	EXPECT_FALSE(s.Check("abc"));
	EXPECT_EQ(0, new_power);
	

}


TEST(SetPower, EmptySetReturnZero) {
	Set s;
	EXPECT_EQ(0, s.Power());
}

TEST(SetPower, NonEmptySetReturnValidVal) {
	Set s;
	s.Add("qwe");
	s.Add("abc");
	int size = 2;
	EXPECT_EQ(size, s.Power());
}

TEST(SetIncludes, NoCommonElementsReturnFalse) {
	Set s;
	s.Add("asd");
	s.Add("bcd");
	Set q;
	q.Add("zxc");
	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, IncludeItselfReturnTrue) {
	Set s;
	s.Add("asd");
	s.Add("bcd");
	s.Add("zxc");
	s.Add("dde");
	EXPECT_TRUE(s.Includes(s));
}

TEST(SetIncludes, EmptySetAsParamReturnTrue) {
	Set s;
	s.Add("asd");
	s.Add("bcd");
	Set q;
	EXPECT_TRUE(s.Includes(q));
}
TEST(SetIncludes, BothEmptySetsReturnTrue) {
	Set s;
	Set q;
	EXPECT_TRUE(s.Includes(q));
}
TEST(SetIncludes, MainSetEmptyReturnFalse) {
	Set s;
	Set q;
	q.Add("asd");
	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, EqualPowerAndHaveSomeCommonElemsReturnFalse) {
	Set s;
	s.Add("abc");
	s.Add("xdd");
	
	Set q;
	q.Add("asd");
	q.Add("wes");

	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, SecondSetBiggerReturnFalse) {
	Set s;
	s.Add("abc");
	s.Add("xdd");

	Set q;
	q.Add("asd");
	q.Add("wes");
	q.Add("ccx");
	EXPECT_FALSE(s.Includes(q));
}

TEST(SetIncludes, IncludesReturnTrue) {
	Set s;
	s.Add("abc");
	s.Add("xdd");
	s.Add("zxc");
	Set q;
	q.Add("abc");
	EXPECT_TRUE(s.Includes(q));
}

TEST(SetIncludes, EqualSetsReturnTrue) {
	Set s;
	s.Add("xdd");
	s.Add("abc");
	s.Add("zxc");
	Set q;
	q.Add("abc");
	q.Add("zxc");
	q.Add("xdd");

	EXPECT_TRUE(s.Includes(q));
}



TEST(SetUnion, EmptySetsReturnEmptySet) {
	Set s;
	Set q;
	Set result = s.Union(q);
	EXPECT_EQ(result.Power(),0);
}

TEST(SetUnion, UnionItselfReturnValidVal) {
	Set s;

	s.Add("xdd");
	s.Add("abc");
	s.Add("zxc");
	Set result = s.Union(s);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));
}

TEST(SetUnion, FirstSetEmptyReturnSecond) {
	Set s;
	Set q;
	q.Add("bcv");
	q.Add("asd");


	Set result = s.Union(q);
	EXPECT_EQ(result.Power(), q.Power());
	EXPECT_TRUE(result.Includes(q));
	EXPECT_TRUE(q.Includes(result));
}


TEST(SetUnion, SecondSetEmptyReturnFirst) {
	Set s;
	Set q;
	s.Add("bcv");
	s.Add("asd");


	Set result = s.Union(q);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));

}

TEST(SetUnion, EqualSetsReturnValidVal) {
	Set s;

	s.Add("bcv");
	s.Add("asd");
	Set q;
	q.Add("bcv");
	q.Add("asd");

	Set result = s.Union(q);
	EXPECT_EQ(result.Power(), s.Power());

	EXPECT_TRUE(result.Includes(q));
	EXPECT_TRUE(q.Includes(result));

	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));

}

TEST(SetUnion, CommonElemsReturnValidVal) {
	Set s;

	s.Add("bcv");
	s.Add("asd");
	Set q;
	q.Add("asd");
	q.Add("ok");
	q.Add("wwe");

	Set result = s.Union(q);
	EXPECT_EQ(result.Power(), s.Power()+q.Power()-1);

	EXPECT_TRUE(result.Includes(q));

	EXPECT_TRUE(result.Includes(s));

}

TEST(SetIntersection, EmptySetsReturnEmpty) {
	Set s;
	Set q;
	Set result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 0);
}

TEST(SetIntersection, IntersectItselfReturnValidVal) {
	Set s;

	s.Add("bcv");
	s.Add("asd");
	Set result = s.Intersection(s);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Includes(s));

	EXPECT_TRUE(s.Includes(result));
}


TEST(SetIntersection, MainSetEmptyReturnEmpty) {
	Set s;
	Set q;
	q.Add("asd");
	q.Add("bcd");
	Set result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_FALSE(result.Check("bcd"));
}

TEST(SetIntersection, SecondSetEmptyReturnEmpty) {
	Set s;
	Set q;
	s.Add("asd");
	s.Add("bcd");
	Set result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_FALSE(result.Check("bcd"));
}


TEST(SetIntersection, HaveCommonElemsReturnValidVal) {
	Set s;
	s.Add("asd");//
	s.Add("bcd");
	s.Add("zxc");//
	s.Add("ttt");
	Set q;
	q.Add("asd");//
	q.Add("zxc");//
	q.Add("qwe");
	q.Add("rty");
	Set result = s.Intersection(q);
	EXPECT_EQ(result.Power(), 2);
	EXPECT_TRUE(result.Check("asd"));
	EXPECT_TRUE(result.Check("zxc"));
	EXPECT_FALSE(result.Check("ttt"));
}

TEST(SetSubtract, BothEmptyReturnEmpty) {
	Set s;
	Set q;
	Set result = s.Subtract(q);
	EXPECT_EQ(s.Power(), 0);


}
TEST(SetSubtract, MainSetEmptyReturnEmpty) {
	Set s;
	Set q;
	q.Add("qwe");
	q.Add("asd");
	Set result = s.Subtract(q);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Check("qwe"));
	EXPECT_FALSE(result.Check("asd"));

}

TEST(SetSubtract, SecondSetEmptyReturnFirstSet) {
	Set s;
	s.Add("qwe");
	s.Add("asd");
	Set q;
	Set result = s.Subtract(q);
	EXPECT_EQ(result.Power(), s.Power());
	EXPECT_TRUE(result.Check("qwe"));
	EXPECT_TRUE(result.Check("asd"));

}


TEST(SetSubtract, SubtractItselfReturnEmpty) {
	Set s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	s.Add("ddw");

	Set result = s.Subtract(s);
	EXPECT_EQ(result.Power(), 0);
}

TEST(SetSubtract, SomeCommonElemsfReturnValidVal) {
	Set s;
	s.Add("qwe");
	s.Add("asd");//
	s.Add("zxc");
	s.Add("ddw");//

	Set q;
	q.Add("ddw");//
	q.Add("asd");//
	q.Add("mnv");
	q.Add("yuu");


	Set result = s.Subtract(q);
	EXPECT_EQ(result.Power(), s.Power()-s.Intersection(q).Power());
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_FALSE(result.Check("ddw"));

}

TEST(SetXOR, EmptySetsReturnEmpty) {
	Set s;
	Set q;
	Set result = s.XOR(q);
	EXPECT_EQ(result.Power(), 0);

}


TEST(SetXOR, OneSetEmptyReturnValidVal) {
	Set s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	Set q;
	Set result = s.XOR(q);
	EXPECT_EQ(result.Power(), s.Power());

	EXPECT_TRUE(result.Includes(s));
	EXPECT_TRUE(s.Includes(result));

}

TEST(SetXOR, XORItselfReturnEmpty) {
	Set s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	Set result = s.XOR(s);
	EXPECT_EQ(result.Power(), 0);
	EXPECT_FALSE(result.Includes(s));

}


TEST(SetXOR, NoCommonElemsReturnUnion) {
	Set s;
	s.Add("qwe");
	s.Add("asd");
	s.Add("zxc");
	Set q;
	q.Add("ghj");
	q.Add("llk");
	Set result = s.XOR(q);
	Set _union;
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
	Set s;
	s.Add("qwe");
	s.Add("asd");//
	s.Add("zxc");
	Set q;
	q.Add("ghj");
	q.Add("asd");//
	Set xor;
	xor.Add("qwe");
	xor.Add("zxc");
	xor.Add("ghj");
	Set result = s.XOR(q);
	EXPECT_EQ(result.Power(), xor .Power());
	EXPECT_FALSE(result.Check("asd"));
	EXPECT_TRUE(result.Includes(xor));
	EXPECT_TRUE(xor.Includes(result));

}
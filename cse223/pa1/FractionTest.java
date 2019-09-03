public class FractionTest {
    public static void main(String[] args) {
        // Test fraction contructors and toString
        Fraction a = new Fraction(1,2);
        Fraction b = new Fraction(3);
        Fraction c = new Fraction(1,0);

        Fraction d = new Fraction(-1, 2);
        Fraction e = new Fraction(1, -5);

        Fraction f = new Fraction(100,400);

        // todo: decide if getNum/getDenum needs to be tested
        // todo: decide what the expected behavior is for getNum/Denom of NaN

        // Test toString
        testToString(a, "1/2");
        testToString(b, "3");
        testToString(c, "NaN");
        testToString(d, "-1/2");
        testToString(e, "-1/5");
        testToString(f, "1/4");

        // Test toDouble
        testToDouble(a, 0.5);
        testToDouble(b, 3.0);
        testToDouble(c, Double.NaN);
        testToDouble(d, -0.5);
        testToDouble(e, -0.2);
        testToDouble(f, 0.25);

        testAdd(new Fraction(1,2), a, new Fraction(1));
        testAdd(new Fraction(1,2), b, new Fraction(7,2));
        testAdd(new Fraction(3), b, new Fraction(6));
        testAdd(new Fraction(1,2), d, new Fraction(0));
        testAdd(new Fraction(-1,2), e, new Fraction(-7,10));
        testAdd(c, a, c); // NaN test
        testAdd(c, d, c); // NaN test
        
        testSub(new Fraction(1,2), a, new Fraction(0));
        testSub(new Fraction(3), a, new Fraction(5,2));
        testSub(new Fraction(1,2), b, new Fraction(-5,2));
        testSub(new Fraction(1,2), d, new Fraction(1));
        testSub(new Fraction(-1,2), d, new Fraction(0));
        testSub(new Fraction(-1,2), e, new Fraction(-3,10));
        testSub(c, a, c); // NaN test
        testSub(c, d, c); // NaN test

        testMul(new Fraction(1,2), a, new Fraction(1,4));
        testMul(new Fraction(1,2), b, new Fraction(3,2));
        testMul(new Fraction(3), b, new Fraction(9));
        testMul(new Fraction(1,2), d, new Fraction(-1,4));
        testMul(new Fraction(-1,2), e, new Fraction(1,10));
        testMul(c, a, c); // NaN test
        testMul(c, d, c); // NaN test

        testDiv(new Fraction(1,2), a, new Fraction(1));
        testDiv(new Fraction(3), a, new Fraction(6));
        testDiv(new Fraction(1,2), b, new Fraction(1,6));
        testDiv(new Fraction(1,2), d, new Fraction(-1));
        testDiv(new Fraction(-1,2), d, new Fraction(1));
        testDiv(new Fraction(-1,2), e, new Fraction(5,2));
        testDiv(c, a, c); // NaN test
        testDiv(c, d, c); // NaN test

        System.out.println("Tests Successful!");
    }

    private static void testToString(Fraction a, String exp) {
        String testCase = a.toString();
        assert testCase.equals(exp) : "Failed toString: expected "+exp+" got "+testCase;
    }

    private static void testToDouble(Fraction a, double exp) {
        double testCase = a.toDouble();
        if (Double.isNaN(exp)) {
            assert Double.isNaN(testCase) : "Failed toDouble: expected NaN got "+testCase;
        }
        else {
            assert testCase == exp : "Failed toDouble: expected "+exp+" got "+testCase;
        }
    }

    private static void testAdd(Fraction a, Fraction b, Fraction exp) {
        Fraction testCase = a.add(b);
        if (exp.isNaN()) {
            assert testCase.isNaN() : "Failed add: expected NaN got "+testCase;
        }
        else {
            assert testCase.getNum() == exp.getNum() && testCase.getDenom() == exp.getDenom()
                : "Failed add: expected "+exp+" got "+testCase;
        }
    }
    
    private static void testSub(Fraction a, Fraction b, Fraction exp) {
        Fraction testCase = a.sub(b);
        if (exp.isNaN()) {
            assert testCase.isNaN() : "Failed sub: expected NaN got "+testCase;
        }
        else {
            assert testCase.getNum() == exp.getNum() && testCase.getDenom() == exp.getDenom()
                : "Failed sub: expected "+exp+" got "+testCase;
        }
    }

    private static void testMul(Fraction a, Fraction b, Fraction exp) {
        Fraction testCase = a.mul(b);
        if (exp.isNaN()) {
            assert testCase.isNaN() : "Failed mul: expected NaN got "+testCase;
        }
        else {
            assert testCase.getNum() == exp.getNum() && testCase.getDenom() == exp.getDenom()
                : "Failed mul: expected "+exp+" got "+testCase;
        }
    }

    private static void testDiv(Fraction a, Fraction b, Fraction exp) {
        Fraction testCase = a.div(b);
        if (exp.isNaN()) {
            assert testCase.isNaN() : "Failed div: expected NaN got "+testCase;
        }
        else {
            assert testCase.getNum() == exp.getNum() && testCase.getDenom() == exp.getDenom()
                : "Failed div: expected "+exp+" got "+testCase;
        }
    }
}


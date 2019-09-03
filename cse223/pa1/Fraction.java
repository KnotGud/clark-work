/*
 * Author:      Daniel Lee
 * Class:       CSE 223
 * Synopsis:    Fraction is a class that describes a mathmatical fraction.
 *              This class also allows for basic mathmatical operations between fractions.
 *              These include Addition, Subtraction, Multiplication, and Division
 */


class Fraction {
    private int num; // num is the numerator of a fraction
    private int denom = 1; // denom is the denominator of a fraction (defaults to 1)
    private boolean isNaN = false; // isNaN is used to determine NaN status for calculations

    // constructor for an integer fraction of N/1
    public Fraction(int num) {
        this.num = num;
        reduce();
    }

    // constructor for a fraction of N/N
    public Fraction(int num, int denom) {
        this.num = num;
        this.denom = denom;
        isNaN = denom == 0;
        reduce();
    }

    // toDouble provides double conversion to this object
    public double toDouble() {
        if (isNaN) {
            return Double.NaN;
        }
        return (double)num / (double)denom;
    }
    
    // toString provides string conversion to this object
    public String toString() {
        if (isNaN) { return "NaN"; }
        if (denom == 1) { return num+""; }
        return num + "/" +  denom;
    }

    // getNum exposes read access to the numerator
    public int getNum() {
        return num;
    }

    // getDenom exposes read access to the denominator
    public int getDenom() {
        return denom;
    }

    // isNaN exposes read access to isNaN
    public boolean isNaN() {
        return isNaN;
    }

    // add adds the given fraction and this fraction, returning a new fraction sum
    public Fraction add(Fraction n) {
        Fraction ret = new Fraction(num, denom);
        if (isNaN || n.isNaN) {
            ret.isNaN = true;
        } else {
            ret.num *= n.denom;
            ret.num += denom * n.num;
            ret.denom *= n.denom;
        }
        ret.reduce();
        return ret;
    }

    // sub subtracts the given fraction from this fraction, returning a new fraction difference
    public Fraction sub(Fraction n) {
        Fraction ret = new Fraction(num, denom);
        if (isNaN || n.isNaN) {
            ret.isNaN = true;
        } else {
            ret.num *= n.denom;
            ret.num -= denom * n.num;
            ret.denom *= n.denom;
        }
        ret.reduce();
        return ret;
    }

    // mul multiplies the given fraction and this fraction, returning a new fraction product
    public Fraction mul(Fraction n) {
        Fraction ret = new Fraction(num, denom);
        if (isNaN || n.isNaN) {
            ret.isNaN = true;
        } else {
            ret.num *= n.num;
            ret.denom *= n.denom;
        }
        ret.reduce();
        return ret;
    }

    // div divides the given fraction from this fraction returning a new fraction quotient
    public Fraction div(Fraction n) {
        Fraction ret = new Fraction(num, denom);
        if (isNaN || n.isNaN) {
            ret.isNaN = true;
        } else {
            ret.num *= n.denom;
            ret.denom *= n.num;
        }
        ret.reduce();
        return ret;
    }


    // reduce simplifies the fraction and fixes negatives in the denominator.
    private void reduce() {
        // fix excessive denominators
        if (num == 0) {
            denom = 1;
        }

        // standardizes NaN
        if (isNaN) {
            num = 1;
            denom = 0;
        }
        
        // Change negative from denom to num
        if (denom < 0) {
            denom *= -1;
            num *= -1;
        }

        // Simplifies fraction
        int n, d, temp;
        n = Math.abs(num);
        d = Math.abs(denom);
        if (n != 0 && d != 0) {
            temp = (d > n) ? Fraction.gcd(d, n) : Fraction.gcd(n, d);
            //temp = (d > n) ? Fraction.gcd_recurse(d, n) : Fraction.gcd_recurse(n, d);
            denom /= temp;
            num /= temp;
        }
    }
    
    // gcd uses Euclidean Algorithm to get the GCD
    // written as static because it doesn't require obj specific parts to function
    private static int gcd(int l, int s) {
        int r;
        while (true) {
            r = l%s;
            if (r == 0) {
                break;
            }
            l = s;
            s = r;
        }
        return s;
    }

    // gcd_recurse uses Euclidean algorithm to get gcd
    // this was build using recursion for practice
    private static int gcd_recurse(int l, int s){
        int r = l%s;
        if (r == 0) { return s;}
        return Fraction.gcd_recurse(s, r);
    }
}

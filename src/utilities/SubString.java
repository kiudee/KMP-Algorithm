package utilities;

public class SubString {
    private String substring;
    private int    shiftT1;
    private int    shiftT2;

    public SubString(String substring, int shiftT1, int shiftT2) {
        this.substring = substring;
        this.shiftT1 = shiftT1;
        this.shiftT2 = shiftT2;
    }

    public SubString(String substring, int shift) {
        this(substring, shift, shift);
    }

    public String getSubstring() {
        return substring;
    }

    public int getShiftT1() {
        return shiftT1;
    }

    public int getShiftT2() {
        return shiftT2;
    }
}

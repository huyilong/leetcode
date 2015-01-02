/*
P   A   H   N
A P L S I I G
Y   I   R

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

public String convert(String s, int nRows) {
    //string to char array very important
    //char[] c = string.toCharArray()
    char[] c = s.toCharArray();
    //find the length of the char array, i.e. the original zigzag length
    int len = c.length;
    //the normal version should be horizon nRows
    StringBuffer[] sb = new StringBuffer[nRows];

    for (int i = 0; i < sb.length; i++) 
        sb[i] = new StringBuffer();

    int i = 0;
    while (i < len) {
        //the key point: we must read every vertical line by 3 words?
        for (int idx = 0; idx < nRows && i < len; idx++) // vertically down
            sb[idx].append(c[i++]);

        for (int idx = nRows-2; idx >= 1 && i < len; idx--) // obliquely up
            sb[idx].append(c[i++]);
    }
    
    for (int idx = 1; idx < sb.length; idx++)
        sb[0].append(sb[idx]);
    return sb[0].toString();
}
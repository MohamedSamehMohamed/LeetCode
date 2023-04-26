public class Solution {
    public int AddDigits(int num) {
        return num <= 9? num: AddDigits((num % 10) + AddDigits(num / 10));
    }
}
class Solution {
public:
    string helper(string str) {
    string dec_to_hex = "0123456789abcdef", res = "";

    int dec_num = stoi(str, nullptr, 16);
    int q = dec_num / 17;
    if ((dec_num % 17) > 8) q = q + 1;
    res = res + dec_to_hex[q] + dec_to_hex[q];
    return res;
}

string similarRGB(string color) {
    return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
}
};
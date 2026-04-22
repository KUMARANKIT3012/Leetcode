class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle); // size_t = used for sizes and indices and it cannot be negative 

        if(found != string::npos){ // !NOT FOUND
            return int(found);
        }
        else{
            return -1;
        }
    }
};

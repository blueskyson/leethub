bool isAnagram(char* s, char* t) {
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2) {
        return false;
    }

    int map1[26] = {0}, map2[26] = {0};
    for (int i = 0; i < len1; i++) {
        int c1 = (int)(s[i] - 'a');
        int c2 = (int)(t[i] - 'a');
        map1[c1] += 1;
        map2[c2] += 1;
    }
    
    for (int i = 0; i < 26; i++) {
        if (map1[i] != map2[i]) {
            return false;
        }
    }
    
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int hashset[26];
    for (int i = 0; i < 26; i++) {
        hashset[i] = INT32_MAX;
    }
    
    for (int i = 0; i < wordsSize; i++) {
        int hashset2[26] = {0};
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            hashset2[words[i][j] - 'a'] += 1;
        }
        
        for (int j = 0; j < 26; j++) {
            if (hashset2[j] < hashset[j]) {
                hashset[j] = hashset2[j];
            }
        }
    }

    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        *returnSize += hashset[i];
    }
    
    char **array = (char**)malloc(*returnSize * sizeof(char*));
    int idx = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < hashset[i]; j++) {
            array[idx] = (char*)malloc(sizeof(char) * 2);
            array[idx][0] = 'a' + i;
            array[idx][1] = '\0';
            idx += 1;
        }
    }
    
    return array;
}
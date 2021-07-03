 int *count = new int[26];
        bool *taken = new bool[26];

        for (int i = 0; i < 26; i++){
            count[i] = 0;
            taken[i] = 0;      //false
        }

        for (auto it : s) {
            int ch = it - 97;
            count[ch]++;
        }
         string result = "";
        for (auto it : s) {
            int ch = it - 97;                 //97 is the ascii value of 'a'
		                          	          //whenever you do any operation on characters, you are mainly doing operations on their ascii value 
			                                 //if you subtract two characters, you'll get result as ascii value. And then it's upto on you if you want to convert that ascii into character or want it into "int" only.
            count[ch]--;

            if (taken[ch])       // already present in result
                continue;

            while (!result.empty() && it < result.back() && count[result.back()-97]) {
                taken[result.back()-97] = false;    //we don't want this bigger in front side in resultant string and due to it's reptition in upcoming stream, can be placed further according to requirement. so,now not in result
                result.pop_back();
            }
            result += it;
            taken[ch] = true;    // mark that we have taken smallest ascii value character, here taking into result
        }

        return result;
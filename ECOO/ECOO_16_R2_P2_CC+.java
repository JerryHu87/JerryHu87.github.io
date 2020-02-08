import java.util.*;
import java.io.*;


public class P2_R2_16_CCplus {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));//Fast input to speed up time
		for(int z = 0;z<10;z++) {
			int k = (Integer.parseInt(input.readLine()))%26;
			/*
			 * If k is greater than 26 it will simply loop back to itself after reaching 26,i.e.k ==  27 equals one shift to the right; therefore,
			 * k == 27 == 1, because k can be up to 10^9, possible integer overflow; therefore, we modulo 26
			 */
			String [] words = input.readLine().split(" ");
			if(words.length == 1) {//means it is an encrypted word
				String word = words[0];
				String answer = "";
				int [] psa = new int [word.length()];//prefix-sum array can save us time by not having to constantly sum all the numbers at higher indices
				psa[word.length()-1] = word.charAt(word.length()-1);
				int c = word.charAt(word.length()-1)-k;
				if(c < 'a') {//not in range of char, i.e. 'a' - k, if k == 2, add 26 because we have come back to the start
					c += 26;
				}
				psa[word.length()-1] = c-'a';
				answer = Character.toString((char)(c)) +answer;
				for(int i = word.length()-2;i >= 0;i--) {
					int current = word.charAt(i)-k-psa[i+1];//minus k and the sum to the right to get original value
					while(current < 'a') {//put it back into the range of lowercase letters
						current += 26;
					}
					answer = Character.toString((char)current) + answer;
					psa[i] = psa[i+1] + answer.charAt(0) - 'a';
				}
				int wordnum = 26*(answer.charAt(0)-'a') + (answer.charAt(1)-'a');
				answer = answer.substring(2);
				List<Integer> length = new ArrayList<Integer>();//length of the words to output the answer
				while(wordnum > 0) {//figure out how many words are in the sentence
					length.add(answer.charAt(0)-'a');//figure out the length of all the words and add it to a list
					answer = answer.substring(1);
					wordnum--;
				}
				int index = 0;
				for(int i = 0;i<length.size();i++) {//we know all the lengths so we output the value in the list followed by whitespace
					for(int j = index;j<length.get(i)+index;j++) {
						System.out.print(answer.charAt(j));//print out the answer
					}
					System.out.print(" ");//make sure to add a whitespace
					index += length.get(i);
				}
				System.out.println();//Also skip a line as well
			}
			else {
				String answer = "";
				String temp = "";
				temp += Character.toString((char)((words.length/26) + 'a')) + Character.toString((char)((words.length%26) + 'a'));
				//This is the value of the number of words, we change it to base 26 and convert it to a char by adding 'a' and casting the number
				for(int i = 0;i<words.length;i++) {
					temp += Character.toString((char)(words[i].length() + 'a'));
					//figure out the length of each word and it is already guaranteed to be less than 26 so we do not need to convert to base 26
				}
				for(int i = 0;i<words.length;i++) {
					temp += words[i];//add all the words to the end
				}
				int [] psa = new int [temp.length()];//use psa to avoid constantly resumming values
				psa[0] = (temp.charAt(0)-'a');
				for(int i = 1;i<temp.length();i++) {
					psa[i] = psa[i-1] + (temp.charAt(i)-'a');//implementation of psa
				}
				for(int i = 0;i<temp.length();i++) {
					int current = temp.charAt(i) + k + psa[psa.length-1] - psa[i];
					while(current > 'z') {
						current -= 26;
					}
					answer += Character.toString((char)(current));
				}
				System.out.println(answer);
			}
		}
		input.close();
	}

}

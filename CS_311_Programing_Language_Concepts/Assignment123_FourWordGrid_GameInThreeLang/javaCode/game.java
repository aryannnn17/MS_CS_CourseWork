import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
class game{
    static void loadDictionary(String fileName, Set<String> dictionary) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine())!=null) {
                if (line.length()==4) {
                    dictionary.add(line.toUpperCase());
                }
            }
        } catch (IOException e) {
            System.err.println("Error loading dictionary: ");
        }
    }
    static Set<String> selectWords(Set<String> dictionary){
        Random rand = new Random();
        Set<String> selectedWords=new HashSet<>();
        List<String> al=new ArrayList<>();
        for(String i:dictionary)al.add(i);
        while(selectedWords.size()<4){
            selectedWords.add(al.get(rand.nextInt(dictionary.size())));
        }
        return selectedWords;
    }
    static void printGrid(Set<String> selectedWords){
        List<Character> al=new ArrayList<>();
        for(String i:selectedWords){
            for(char c: i.toCharArray()){
                al.add(c);
            }
        }
        System.out.println(al);
        Collections.shuffle(al);
        int k=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                System.out.print(al.get(k++)+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args){
        Scanner obj=new Scanner(System.in);
        int chances=3;
        System.out.println("You have 3 attempts to guess the right answer");
        Set<String> dictionary=new HashSet<>();
        loadDictionary("Dictionary_4letterwords.txt", dictionary);
        Set<String> selectedWords=selectWords(dictionary);
        printGrid(selectedWords);
        //System.err.println(dictionary);
        //System.out.println(selectedWords);
        while(chances!=0){
            System.out.println("Enter Your 4 words: ");
            boolean correct=true;
            String[] str=new String[4];
            for(int i=0;i<4;i++){
                System.out.print("Enter Word "+(i+1)+" :");
                str[i]=obj.next();
            }
            for(String i:str){
                if(!selectedWords.contains(i)){
                    correct=false;
                 }
            }
            if(correct){
                System.out.print("Congratulations, You have successfully guesssed the right words");
                return;
            }
            chances--;
            if(chances==0)break;
            System.out.print("Wrong guess, Try again..."+chances+" Attempts left");
        }
        System.out.print("No more attempts left...");
    }
}
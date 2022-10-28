import java.io.*;
import java.util.*;

class Main{
    // With a queue of all people, this problem becomes solvable in linear time
    // We can keep a queue of the people in front of a given person representing each cut
    // It's not necessary to traverse the entire list when a cut happens;
    // We can just check when the person who was cut is in the front of the queue
    // I'll implement with a deque so we can simulate a cut by adding a person to the front


    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());

        Deque<String> line = new ArrayDeque<>();
        //A tricky part here is we're given people as strings instead of integers
        //A map let's us index a person by their name

        //A better approach would be to map each string to an integer, and then run
        //the program using the integers as indices. This would mean we don't have
        //to keep calling the map, which takes time. I think the version here is
        //more readable though.

        HashMap<String, Queue<String>> cuts = new HashMap<>();
        HashSet<String> deleted = new HashSet<>();
        for(int i = 0; i < n; i++){
            line.add(in.readLine());
        }
        int q = Integer.parseInt(in.readLine());
        while(q-- > 0){
            StringTokenizer st = new StringTokenizer(in.readLine());
            String command = st.nextToken();
            if(command.equals("cut")){
                String x = st.nextToken(), y = st.nextToken();
                if(!cuts.containsKey(x)){
                    cuts.put(x, new LinkedList<>()); // Initialize the queue for this person
                }
                cuts.get(x).add(y); // Add the person to the queue
            }else{ // command.equals("leave")
                String x = st.nextToken();
                deleted.add(x); 
            }
        }

        StringBuilder output = new StringBuilder();
        while(!line.isEmpty()){
            String person = line.peekFirst();
            if(cuts.containsKey(person) && cuts.get(person).size() > 0){
                // If the person has a queue of people in front of them, add them to the front
                line.addFirst(cuts.get(person).poll());
            }else{
                if(!deleted.contains(person)){
                    output.append(person);
                    output.append('\n');
                }
                line.pollFirst();
            }   
        }
        System.out.print(output);
    }
}

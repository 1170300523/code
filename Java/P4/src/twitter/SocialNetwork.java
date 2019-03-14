/* Copyright (c) 2007-2016 MIT 6.005 course staff, all rights reserved.
 * Redistribution of original or derived work requires permission of course staff.
 */
package twitter;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * SocialNetwork provides methods that operate on a social network.
 * 
 * A social network is represented by a Map<String, Set<String>> where map[A] is
 * the set of people that person A follows on Twitter, and all people are
 * represented by their Twitter usernames. Users can't follow themselves. If A
 * doesn't follow anybody, then map[A] may be the empty set, or A may not even exist
 * as a key in the map; this is true even if A is followed by other people in the network.
 * Twitter usernames are not case sensitive, so "ernie" is the same as "ERNie".
 * A username should appear at most once as a key in the map or in any given
 * map[A] set.
 * 
 * DO NOT change the method signatures and specifications of these methods, but
 * you should implement their method bodies, and you may add new public or
 * private methods or classes if you like.
 */
public class SocialNetwork { 

    /**
     * Guess who might follow whom, from evidence found in tweets.
     * 
     * @param tweets
     *            a list of tweets providing the evidence, not modified by this
     *            method.
     * @return a social network (as defined above) in which Ernie follows Bert
     *         if and only if there is evidence for it in the given list of
     *         tweets.
     *         One kind of evidence that Ernie follows Bert is if Ernie
     *         @-mentions Bert in a tweet. This must be implemented. Other kinds
     *         of evidence may be used at the implementor's discretion.
     *         All the Twitter usernames in the returned social network must be
     *         either authors or @-mentions in the list of tweets.
     */
    public static Map<String, Set<String>> guessFollowsGraph(List<Tweet> tweets) {
    	 Map<String, Set<String>> followsGraph = new HashMap<>();
    	 for(Tweet iTweet:tweets)
    	 {
    		 Set<String> set = new HashSet<String>();
    		 String bString=iTweet.getText();
     		 String regEx="@\\w*";
     	
     		Pattern p = Pattern.compile(regEx);
     		Matcher m = p.matcher(bString);

     		while (m.find()) {
     		String result=m.group();
     		result = result.toLowerCase().replace("@", "");
     		set.add(result);
     		}
     		followsGraph.put(iTweet.getAuthor().toLowerCase(), set);
    	 }
    	 return followsGraph;
    	 
    }
    
    

    /**
     * Find the people in a social network who have the greatest influence, in
     * the sense that they have the most followers.
     * 
     * @param followsGraph
     *            a social network (as defined above)
     * @return a list of all distinct Twitter usernames in followsGraph, in
     *         descending order of follower count.
     */
    public static List<String> influencers(Map<String, Set<String>> followsGraph) {
    	List<String> influencers = new ArrayList<String>();
    	Map<String, Integer> nMap = new HashMap<>();
    	Collection<Set<String>> str = followsGraph.values();
    	for(Set<String> iSet :str) {
    		for(String iString:iSet)
    		{
    			if(nMap.containsKey(iString))
    				nMap.put(iString, nMap.get(iString)+1);
    			else {
					nMap.put(iString, 1);
				}
    		}
    	}
    	ArrayList<Entry<String, Integer>> list = new ArrayList<Map.Entry<String,Integer>>(nMap.entrySet());
        //然后通过比较器来实现排序
        Collections.sort(list,new Comparator<Map.Entry<String,Integer>>() {
            //升序排序
            public int compare(Entry<String, Integer> o1,
                    Entry<String, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
            
        });
        for(Map.Entry<String,Integer> mapping:list){ 
            //System.out.println(mapping.getKey()+":"+mapping.getValue()); 
        	influencers.add(mapping.getKey());
       } 
    	return influencers;
    }
    
    
    public static Map<String, Set<String>> myguessFollowsGraph(List<Tweet> tweets) {
   	 Map<String, Set<String>> followsGraph = new HashMap<>();
   	Map<String, Set<String>> followsGraph2 = new HashMap<>();
   	
   	followsGraph = guessFollowsGraph(tweets);
   	Set<String> dSet = new HashSet();
   	 for( Map.Entry<String, Set<String>> i:followsGraph.entrySet())
   	 {	  	Set<String> iSet  = i.getValue();
   		 for(String iString :i.getValue()) {
   			 if(followsGraph.keySet().contains(iString))
   					 {
   				 
   				dSet = new HashSet();
   				 for(String iString2 : followsGraph.get(iString)) 
   						{dSet.add(iString2);
   						System.out.println("here++");
   						}
   						System.out.println("here--");
   						for(String jString:iSet)
   							dSet.add(jString);
   					}
   			
   		 }
   		 followsGraph2.put(i.getKey(),dSet );
   		System.out.println("here wai");
   	 }
   	System.out.println("here ok"); 
   
   	 return followsGraph2;

    		}
}


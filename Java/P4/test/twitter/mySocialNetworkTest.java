package twitter;

import static org.junit.Assert.*;

import java.lang.reflect.Array;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import org.junit.Test;

public class mySocialNetworkTest {

	@Test
	public void testMyguessFollowsGraph() {
		Instant d1 = Instant.parse("2016-02-17T10:00:00Z");
		Instant d2 = Instant.parse("2016-02-17T10:00:00Z");
		Instant d3 = Instant.parse("2016-02-17T10:00:00Z");
		//System.out.println("here");
		Tweet tweet1 = new Tweet(1, "lee", "is it reasonable @tim @tom talk about rivest so much?", d1);
		Tweet tweet2 = new Tweet(2, "tom", "is it reasonable to talk @kim @god about rivest so much?", d2);
		Tweet tweet3 = new Tweet(3, "kim", "is it reasonable to talk about rivest so much?", d3);
		Map<String, Set<String>> followsGraph = new HashMap<>();
		//System.out.println("here");
		followsGraph = SocialNetwork.myguessFollowsGraph(Arrays.asList(tweet1, tweet2,tweet3));
		//System.out.println("here");
		System.out.println(followsGraph.get("lee"));
		assertTrue(followsGraph.get("lee").contains("kim"));
	}

}

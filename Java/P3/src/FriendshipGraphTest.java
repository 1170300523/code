import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class FriendshipGraphTest {
	
	
	

	
	@Test
	void testAddVertex() {
		
		FriendshipGraph g = new FriendshipGraph();
		
		person k = new person("j");
		person a= new person("a");
		person b= new person("b");
		person c= new person("c");
		assertEquals(1, g.addVertex(k));
		assertEquals(2, g.addVertex(a));
		assertEquals(3, g.addVertex(b));
		assertEquals(4, g.addVertex(c));

	}

	@Test
	void testAddEdge() {
FriendshipGraph g = new FriendshipGraph();
		
		person k = new person("j");
		person a= new person("a");
		person b= new person("b");
		person c= new person("c");
		g.addVertex(k);
		g.addVertex(a);
		g.addVertex(b);
		g.addVertex(c);
		assertEquals(1,g.addEdge(c, k) );
		assertEquals(2,g.addEdge(c, a) );
		
		
	}

	@Test
	void testGetDistance() {
FriendshipGraph g = new FriendshipGraph();
		
		person k = new person("j");
		person a= new person("a");
		person b= new person("b");
		person c= new person("c");
		g.addVertex(k);
		g.addVertex(a);
		g.addVertex(b);
		g.addVertex(c);
		g.addEdge(k, c);
		g.addEdge(c, a);
		
		assertEquals(2,g.getDistance(k, a));
		assertEquals(-1,g.getDistance(k, b));
		assertEquals(0,g.getDistance(k, k) );
	
	}

}

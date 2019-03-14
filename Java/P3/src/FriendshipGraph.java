import java.util.ArrayList;



class vertex{
	int distance;
}

public class FriendshipGraph {
	public int len = 0,flag = 0,edge=0,fflag = 0;
	private vertex[][] graph ;
	private  ArrayList<person> vList = new ArrayList<>();
	
	
	public int addVertex(person s) {
		for(person i:vList)
			if(i.name == s.name)
				return len;
		len ++;
		vList.add(s);
		return len;
	}
	
	public void init() {
		this.graph = new vertex[len][len];
		for(int i=0;i< len;i++)
			for(int j=0;j< len;j++)
				{
				graph[i][j] = new vertex();
				graph[i][j].distance = 1000;
				}
		for(int i =0;i<len;i++)
			graph[i][i].distance = 0;
	}

	public int addEdge(person a,person b)
	{	
		int i = vList.indexOf(a);
		int j = vList.indexOf(b);
		if(flag == 0) {
			init();
			flag =1;
		}
	try {
		graph[i][j].distance = 1;
		graph[j][i].distance = 1;
		edge++;
		}catch (Exception e) {
		System.out.println("name repeat");
	}
	return edge;
	}
	
	public void floyd() {
		for(int k=0;k<len;k++)
			for(int i=0;i<len;i++)
				for(int j=0;j<len;j++)
				{
					if(graph[i][j].distance > graph[i][k].distance +graph[k][j].distance)
						graph[i][j].distance = graph[i][k].distance +graph[k][j].distance;		
				}
		
	}
	public int getDistance(person a,person b) {
		int i = vList.indexOf(a);
		int j = vList.indexOf(b);
		if(fflag == 0) {
			floyd();
			fflag = 1;
		}
		int k =graph[i][j].distance;
		return k<1000 ?k:-1;
	}

	public static void main(String[] args) {
		FriendshipGraph g = new FriendshipGraph();
		person k ,a,b,c;
		k = new person("j");
		a = new person("a");
		b = new person("b");
		c = new person("c");
		g.addVertex(k);
		g.addVertex(a);
		g.addVertex(b);
		g.addVertex(c);
		g.addEdge(k, c);
		g.addEdge(c, a);
		System.out.println(g.vList.size());
		System.out.println(g.getDistance(k, a));
		System.out.println(g.getDistance(k, b));
		System.out.println(g.getDistance(k, k));
	}

}


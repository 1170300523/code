package notebook;

import java.util.ArrayList;
import java.util.HashMap;

import javax.print.attribute.Size2DSyntax;

public class notebook {
	private ArrayList<String> note = new ArrayList<String>();  //容器
	private int  size = 0;
	
	//创建哈希表
	public HashMap<Integer, String> cname = new HashMap<Integer,String>();
	
	public void cpush()
	{
		cname.put(1, "yes");  //将信息键入哈希表
		cname.put(10, "ye");
		cname.put(100, "ys");
	}
	
	
	public void addstr(String s)
	{
		note.add(s);
	}
	
	public int getsize()
	{
		return note.size();
	}
	
	public String getnote(int index)
	{
		return note.get(index);
	}
	
	public String[]  list()
	{
		String[]  a = new String[note.size()];
		note.toArray(a);
		return a;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*notebook n = new notebook();
		n.addstr("asdasdS");
		n.addstr("safas");
		System.out.println(n.getsize());
		System.out.println(n.getnote(1));*/
		notebook k = new notebook();
		k.cpush();
		System.out.println(k.cname);
	}

}

package hello;

import java.util.Scanner;

public class Hello {
	
	
	public static void isp(int i,int j) {
		
		int s = 0;
		for (int k = i; k < j; k++) {
			s += k;
		}
		System.out.println(i+"to"+j+"="+(s));
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("dshgdfg");		//printline会自动回车,但print不会
		
		Scanner in =  new Scanner(System.in);  //设置一个扫描变量,用于输入
		
		int price;
		int amount ;   //设置为一个常量,值不能被改变
		System.out.print("请输入票面:");
		amount = in.nextInt();
		System.out.print("请输入价格:");
		price = in.nextInt();
		
		int a,b,c;
		a = b = c =3;	//可以连续赋值
		
		double k = 1.233;
		k = (int)(k);		//强制类型转换,记得两个括号 
		
		System.out.println(amount - price);
		System.out.println(amount > price);
		
		if(amount > 50) 
			System.out.println("it's ok");	//条件语句,和C一样
		else if (amount ==1000) {
			System.out.println("okk");
			
		}
		else 
			System.out.println("no");
		
		
		switch (amount) {				//switch同c语言
		case 100: System.out.println("q");break;
		case 200: System.out.println("w");break;
		default:
			break;
		}
		
		while(in.nextInt()<100) {		//same with c, do-while,for same with c
			System.out.println("okk");
			
		}
		
		// ! ,&&,||   逻辑运算
		
		int[] ak = new int[100];     //数组,  一个是int[]在前 ,一个是new int[100]在后,数组大小可为变量
		int[] al = {1,2,3};   //可以直接 
		int[][] kk = new int[2][3];
		
		
		a = ak.length;   //数组的性质直接用
		boolean aa = false;   //布尔类型
		
		for(int i: ak)			//foreach语句
		{
			if(i ==3)aa = true;
		}
		
		double k1 = Math.sqrt(25) ;  // 平方根
				
		MAIN_LOOP:		
		for(int i =1;i<5;i++)
		{if(i ==3)
			continue MAIN_LOOP ;   //类似于goto
		}
		
		char k2 ='e';
		char k3 = '我';
		boolean k4 = Character.isDigit('4') && Character.isLowerCase('i');
		
		String k5 = "fffffff";
		k5 += "kkkkkk";
		boolean k6 = k5.equals("sdsd")  ;  //判断两个字符串是否相等
		int 		kkk = k5.compareTo("kkkk");   //按照字典序比较
		int k7 = "kkdasdjas".length();		//字符串长度
		k2 = k5.charAt(3);              //字符索引方式
		String k8 = k5.substring(1, 3);  //子串
		//s.indexof()  查找字符串,返回开始位置
		// s.replace(s1,s2);  替换
		// s.trim() 去掉字符串两端的空格
		
		
	}

 		

}

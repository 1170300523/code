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
		System.out.println("dshgdfg");		//printline���Զ��س�,��print����
		
		Scanner in =  new Scanner(System.in);  //����һ��ɨ�����,��������
		
		int price;
		int amount ;   //����Ϊһ������,ֵ���ܱ��ı�
		System.out.print("������Ʊ��:");
		amount = in.nextInt();
		System.out.print("������۸�:");
		price = in.nextInt();
		
		int a,b,c;
		a = b = c =3;	//����������ֵ
		
		double k = 1.233;
		k = (int)(k);		//ǿ������ת��,�ǵ��������� 
		
		System.out.println(amount - price);
		System.out.println(amount > price);
		
		if(amount > 50) 
			System.out.println("it's ok");	//�������,��Cһ��
		else if (amount ==1000) {
			System.out.println("okk");
			
		}
		else 
			System.out.println("no");
		
		
		switch (amount) {				//switchͬc����
		case 100: System.out.println("q");break;
		case 200: System.out.println("w");break;
		default:
			break;
		}
		
		while(in.nextInt()<100) {		//same with c, do-while,for same with c
			System.out.println("okk");
			
		}
		
		// ! ,&&,||   �߼�����
		
		int[] ak = new int[100];     //����,  һ����int[]��ǰ ,һ����new int[100]�ں�,�����С��Ϊ����
		int[] al = {1,2,3};   //����ֱ�� 
		int[][] kk = new int[2][3];
		
		
		a = ak.length;   //���������ֱ����
		boolean aa = false;   //��������
		
		for(int i: ak)			//foreach���
		{
			if(i ==3)aa = true;
		}
		
		double k1 = Math.sqrt(25) ;  // ƽ����
				
		MAIN_LOOP:		
		for(int i =1;i<5;i++)
		{if(i ==3)
			continue MAIN_LOOP ;   //������goto
		}
		
		char k2 ='e';
		char k3 = '��';
		boolean k4 = Character.isDigit('4') && Character.isLowerCase('i');
		
		String k5 = "fffffff";
		k5 += "kkkkkk";
		boolean k6 = k5.equals("sdsd")  ;  //�ж������ַ����Ƿ����
		int 		kkk = k5.compareTo("kkkk");   //�����ֵ���Ƚ�
		int k7 = "kkdasdjas".length();		//�ַ�������
		k2 = k5.charAt(3);              //�ַ�������ʽ
		String k8 = k5.substring(1, 3);  //�Ӵ�
		//s.indexof()  �����ַ���,���ؿ�ʼλ��
		// s.replace(s1,s2);  �滻
		// s.trim() ȥ���ַ������˵Ŀո�
		
		
	}

 		

}

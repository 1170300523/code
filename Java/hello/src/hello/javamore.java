package hello;


public class javamore {
	int total = 0;  //��Ա����
	int balance = 0;
	int price = 80;
	
	// û��public static�ĺ�������Ϊ��ĳ�Ա,��Ϊ��Ա�����ͳ�Ա����
	void setprice(int price)
	{
		this.price = price;
		// �������ӿ���������������ͬʱ,��this.price������������
	}
	
	 javamore() //
	 {
		// TODO Auto-generated constructor stub
		 total = 50;
	}
	 
	 
	void showhello()
	{
		System.out.println("wlecome!");
	}
	
	void showbalance()
	{
		System.out.println("balance is:"+balance);
	}
	
	void insertmoney(int amount)
	{
		balance += amount;
	}
	
	void getfood()
	{
		if(price < balance)
		{
			System.out.println("here you are");
			balance -= price;
		}
		
		else
		{
			System.out.println("money not enough!");
			
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		javamore vm = new javamore();
		vm.showhello();
		vm.showbalance();
		vm.insertmoney(100);
		vm.getfood();
		vm.showbalance();
		
	}

}

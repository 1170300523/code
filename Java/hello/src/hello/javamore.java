package hello;


public class javamore {
	int total = 0;  //成员变量
	int balance = 0;
	int price = 80;
	
	// 没有public static的函数申明为类的成员,分为成员变量和成员函数
	void setprice(int price)
	{
		this.price = price;
		// 当函数接口与类属性名字相同时,用this.price来代替类属性
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

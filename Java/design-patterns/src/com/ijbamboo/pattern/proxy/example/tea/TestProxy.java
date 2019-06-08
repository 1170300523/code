package com.ijbamboo.pattern.proxy.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:09:35
 */
public class TestProxy {
	public static void main(String[] args) {
	       System.out.println("TestProxy: instantiating PotOfTeaProxy");
	       PotOfTeaInterface potOfTea = new PotOfTeaProxy();
	       System.out.println(" ");
	       System.out.println("TestProxy: pouring tea");
	       potOfTea.pourTea();
	   }
	}

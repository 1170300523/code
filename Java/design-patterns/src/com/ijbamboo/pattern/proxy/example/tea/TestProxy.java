package com.ijbamboo.pattern.proxy.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:09:35
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

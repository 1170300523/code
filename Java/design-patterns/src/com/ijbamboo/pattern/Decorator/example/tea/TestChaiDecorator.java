package com.ijbamboo.pattern.Decorator.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:58:52
 */
public class TestChaiDecorator{            
    
   public static void main(String[] args) {
       Tea teaLeaves = new TeaLeaves();
       Tea chaiDecorator = new ChaiDecorator(teaLeaves);
       chaiDecorator.steepTea();
   }
}
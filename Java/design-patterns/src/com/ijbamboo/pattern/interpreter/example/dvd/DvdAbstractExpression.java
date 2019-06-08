package com.ijbamboo.pattern.interpreter.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:22:01
 */
public abstract class DvdAbstractExpression {
	   public abstract String interpret(
			     DvdInterpreterContext dvdInterpreterContext);
			}
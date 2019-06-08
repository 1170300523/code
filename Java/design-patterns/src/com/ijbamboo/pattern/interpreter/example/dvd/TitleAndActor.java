package com.ijbamboo.pattern.interpreter.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:23:59
 */
public class TitleAndActor {

	private String title;
    private String actor;
    public TitleAndActor(String title, String actor) {
        this.title = title;
        this.actor = actor;
    }
    public String getTitle() {return this.title;}
    public String getActor() {return this.actor;}
} 

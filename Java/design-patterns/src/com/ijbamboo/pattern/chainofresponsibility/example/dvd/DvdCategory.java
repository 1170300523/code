package com.ijbamboo.pattern.chainofresponsibility.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:13:27
 */
public class DvdCategory implements TopTitle {  
	   private String category; 
	   private String topCategoryTitle;
	    
	   public DvdCategory(String category) {
	        this.setCategory(category);
	   }    
	   
	   public void setCategory(String categoryIn) {
	       this.category = categoryIn;
	   }
	   public String getCategory() {
	       return this.category;
	   } 
	   public String getAllCategories() {
	       return getCategory();
	   }
	   
	   public void setTopCategoryTitle(String topCategoryTitleIn) {
	       this.topCategoryTitle = topCategoryTitleIn;
	   }
	   public String getTopCategoryTitle() {
	       return this.topCategoryTitle;
	   }
	   
	   public String getTopTitle() {
	       return this.topCategoryTitle;
	   }
	}
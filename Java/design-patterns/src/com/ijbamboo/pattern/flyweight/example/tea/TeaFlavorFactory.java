package com.ijbamboo.pattern.flyweight.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:06:01
 */
public class TeaFlavorFactory {
	TeaFlavor[] flavors = new TeaFlavor[10];
    //no more than 10 flavors can be made
  int teasMade = 0;
  
  public TeaFlavor getTeaFlavor(String flavorToGet) {
      if (teasMade > 0) {
          for (int i = 0; i < teasMade; i++) {
              if (flavorToGet.equals((flavors[i]).getFlavor())) {
                  return flavors[i];
              }
          }
      }
      flavors[teasMade] = new TeaFlavor(flavorToGet);
      return flavors[teasMade++];
  }
  
  public int getTotalTeaFlavorsMade() {return teasMade;}
}

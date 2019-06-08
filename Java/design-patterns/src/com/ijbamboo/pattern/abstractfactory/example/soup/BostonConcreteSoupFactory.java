package com.ijbamboo.pattern.abstractfactory.example.soup;

import com.ijbamboo.pattern.soup.BostonClamChowder;
import com.ijbamboo.pattern.soup.BostonFishChowder;
import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;

/**
 * ��ʿ�� ������ ������
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����1:35:45
 */
public class BostonConcreteSoupFactory extends AbstractSoupFactory{
	public BostonConcreteSoupFactory() {
        factoryLocation = "Boston";
    }
    public ClamChowder makeClamChowder() {
        return new BostonClamChowder();
    }
    public FishChowder makeFishChowder() {
        return new BostonFishChowder();
    }
}

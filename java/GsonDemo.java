package testGson;

import java.util.ArrayList;
import java.util.List;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

public class Main {

	public static void main(String[] args) {
		List<Obj> list=new ArrayList<Obj>();
		for(int i=0;i<3;i++){
			list.add(new Obj(i));
		}
		
		String json = list2json(list);
		System.out.println(json);
		
		List<Obj> list2 = json2list(json);
		
		for(Obj o:list2){
			System.out.println(o.getValue());
		}
		
		Obj obj = new Obj(4);
		json = obj2json(obj);
		System.out.println(json);
		
		Obj obj2 = json2obj(json);
		System.out.println(obj2.getValue());
		
	}
	
	
	public static List<Obj> json2list(String json){
		List<Obj> list= new Gson().fromJson(json, new TypeToken<List<Obj>>(){}.getType());
		return list;
	}
	
	public static String list2json(List<Obj> list){
		String json = new Gson().toJson(list);
		return json;
	}
	
	public static Obj json2obj(String json){
		Obj obj = new Gson().fromJson(json, Obj.class);
		return obj;
	}
	
	public static String obj2json(Obj obj){
		String json = new Gson().toJson(obj);
		return json;
	}
	

}


class Obj{
	int value;
	
	public Obj(int value){
		this.value=value;
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}
	
}

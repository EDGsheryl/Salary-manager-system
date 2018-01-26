#pragma once
#include <set>
using namespace std;

class salary { //工资类
private:
	int num;
public:
	int getnum() {
		return num;
	}
	void add(int _add) {
		num += _add;
	}
	void sub(int _add) {
		num -= _add;
	}
	salary(int _basis) : num(_basis) {}
};


class people { //员工类
protected:
	CString name; //员工姓名
	CString ID; //员工编号
	CString sex; //员工性别
	CString bumen;
	salary *money; //员工关联工资类
public:
	static int stocks;
	people(){
		stocks += 1000;
	};
	people(CString _ID,CString _name,CString _sex, CString _bumen, int _money) : ID(_ID), name(_name), sex(_sex), bumen(_bumen), money(new salary(_money)){
		stocks += 1000;
	}

	virtual ~people() {
		stocks -= 1000;
	}

	virtual CString getInfo() {
		return nullptr;
	};
	CString getID() {
		return ID;
	}

	void update(CString _name, CString _sex, int _money) {
		if (_name != "") name = _name;
		if (_sex != "") sex = _sex;
		if (_money != 0) money->sub(money->getnum()),money->add(_money);
	}
};

class manager : public people {
public:
	manager(CString _ID, CString _name, CString _sex, CString _bumen, int _money) : people(_ID, _name, _sex, _bumen, _money) {}
	~manager() final {}
	CString getInfo() override {
		USES_CONVERSION;
		return ID + "\t " + name + "\t " + sex + "\t " + bumen + "\t " + *(new CString(to_string(money->getnum() + stocks).c_str()));
	}
};

class tech_worker : public people {
public:
	tech_worker(CString _ID, CString _name, CString _sex, CString _bumen, int _money) : people(_ID, _name, _sex, _bumen, _money) {}
	~tech_worker() final {}
	CString getInfo() override {
		return ID + "\t " + name + "\t " + sex + "\t " + bumen + "\t " + *(new CString(to_string(money->getnum() + stocks/2).c_str()));
	}
};

class worker : public people {
public:
	worker(CString _ID, CString _name, CString _sex, CString _bumen, int _money) : people(_ID, _name, _sex, _bumen, _money) {}
	~worker() final {}
	CString getInfo() override {
		return ID + "\t " + name + "\t " + sex + "\t " + bumen + "\t " + *(new CString(to_string(money->getnum()).c_str()));
	}
};

class temp_worker : public people {
public:
	temp_worker(CString _ID, CString _name, CString _sex, CString _bumen, int _money) : people(_ID, _name, _sex, _bumen, _money) {}
	~temp_worker() final {}
	CString getInfo() override {
		return ID + "\t " + name + "\t " + sex + "\t " + bumen + "\t " + *(new CString(to_string(money->getnum()).c_str()));
	}
};

class manage_system {
public:
	static std::set<people* > s;
	static void insert(CString _ID, CString _name, CString _sex, CString _bumen, int _money) {
		if (_bumen == "经理") {
			s.insert(new manager(_ID, _name, _sex, _bumen, _money));
		}
		else if (_bumen == "技术工") {
			s.insert(new tech_worker(_ID, _name, _sex, _bumen, _money));
		}
		else if (_bumen == "普工") {
			s.insert(new worker(_ID, _name, _sex, _bumen, _money));
		}
		else {//临时工 
			s.insert(new temp_worker(_ID, _name, _sex, _bumen, _money));
		}
	}

	static void remove(CString _ID) {
		std::set<people* > ns;
		ns.clear();
		for (set<people*>::iterator it = s.begin(); it != s.end(); it++) {
			if ((*it)->getID() != _ID) ns.insert(*it);
		}
		s = ns;
	}

	static void update(CString _ID, CString _name, CString _sex, CString _bumen, int _money) {
		for (set<people*>::iterator it = s.begin(); it != s.end(); it++) {
			if ((*it)->getID() == _ID) {
				(*it)->update(_name, _sex, _money);
				if (_bumen != "") {
					s.erase(*it);
					insert(_ID, _name, _sex, _bumen, _money);
				}
			}
		}
	}

};

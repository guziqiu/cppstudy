	#include <iostream>
	using namespace std;

	// 底层
	class BankWorker {
	public :
		void saveService() {
			cout << "存款..." << endl;
		}
		void payService() {
			cout << "支付..." << endl;
		}
		void tracnferService() {
			cout << "转账..." << endl;
		}
	};

	// 中层模块
	void doSaveBussiness(BankWorker *worker) {
		worker->saveService();
	}

	void doPayService(BankWorker *worker) {
		worker->payService();
	}
	void doTracnferService(BankWorker *worker) {
		worker->tracnferService();
	}

	// 高层
	void test01() {
		BankWorker *worker = new BankWorker;
		doSaveBussiness(worker);
		doPayService(worker);
		doTracnferService(worker);
	}

	// 
	class AbstractWorker {
	public :
		virtual void dbBusiness() = 0;
	};

	// 存款
	class SaveBankWorkrt : public AbstractWorker {
	public :
		virtual void dbBusiness() {
			cout << " 办理存款业务 ..." << endl;
		}
	};
	// 专门办理付款
	class payBankWorker : public AbstractWorker {
		virtual void dbBusiness() {
			cout << " 支付业务 ..." << endl;
		}
	};
	// 。。。。

	// 中层业务
	void doNewBusiness(AbstractWorker *worker) {
		worker->dbBusiness();
	}

	void test02() {
		AbstractWorker *pay = new payBankWorker();
		doNewBusiness(pay);
		doNewBusiness(new SaveBankWorkrt());
	}

	int main() {
		// test01();
		test02();

		return 0;
	}

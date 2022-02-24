#include <iostream>
#include <vector>

class Ancestor {

public:
	Ancestor() { printf("Ancestor Constructor\n"); }
	~Ancestor() { printf("Ancestor Destructor\n"); }

private:
	int mem_private;
	int func_private() { printf("Ancestor private func\n"); }
	virtual  int vfunc_private() { printf("Ancestor private virtual function\n"); }

protected:
	int mem_protected;
	int func_protected() { printf("Ancestor protected func\n"); }
	virtual int vfunc_protected() { printf("Ancestor protected virtual function\n"); }

public:
	int mem_public;
	int func_public() { printf("Ancestor public func\n"); }
	virtual int vfunc_public() { printf("Ancestor public virtual function\n"); }
};
	;


	class GrandParent : public Ancestor {
	
	public:
		GrandParent() { printf("GrandParent Constructor\n"); }
		~GrandParent() { printf("GrandParent Destructor\n"); }
	
	private:
		int mem_private;
		int func_private() { printf("GrandParent private func\n"); }
		virtual  int vfunc_private() { printf("GrandParent private virtual function\n"); }
	
	protected:
		int mem_protected;
		int func_protected() { printf("GrandParent protected func\n"); }
		virtual int vfunc_protected() { printf("GrandParent protected virtual function\n"); }
	
	public:
		int mem_public;
		int func_public() { printf("GrandParent public func\n"); }
		virtual int vfunc_public() { printf("GrandParent public virtual function\n"); }
	};
		;

		class Parent : public GrandParent {
		
		public:
			Parent() { printf("Parent Constructor\n"); }
			~Parent() { printf("Parent Destructor\n"); }
		
		private:
			int mem_private;
			int func_private() { printf("Parent private func\n"); }
			virtual  int vfunc_private() { printf("Parent private virtual function\n"); }
		
		protected:
			int mem_protected;
			int func_protected() { printf("Parent protected func\n"); }
			virtual int vfunc_protected() { printf("Parent protected virtual function\n"); }
		
		public:
			int mem_public;
			int func_public() { printf("Parent public func\n"); }
			virtual int vfunc_public() { printf("Parent public virtual function\n"); }
		};
			;

			class Me : public Parent {

			public:
				Me() { printf("Me Constructor\n"); }
				Me(int i)
				{
					mem_private = i;
					printf("Me %d Constructor\n", mem_private); 
				}
				~Me() {
					printf("Me %d Destructor\n", mem_private); 
				}

			private:
				int mem_private = 0;
				int func_private() { printf("Me private func\n"); }
				virtual  int vfunc_private() { printf("Me private virtual function\n"); }

			protected:
				int mem_protected;
				int func_protected() { printf("Me protected func\n"); }
				virtual int vfunc_protected() { printf("Me protected virtual function\n"); }

			public:
				int mem_public;
				int func_public() { printf("Me public func\n"); }
				virtual int vfunc_public() { printf("Me public virtual function\n"); }
			};
				;

				class Child : public Me {

				public:
					Child() { printf("Child Constructor\n"); }
					~Child() { printf("Child Destructor\n"); }

				private:
					int mem_private;
					int func_private() { printf("Child private func\n"); }
					virtual  int vfunc_private() { printf("Child private virtual function\n"); }

				protected:
					int mem_protected;
					int func_protected() { printf("Child protected func\n"); }
					virtual int vfunc_protected() { printf("Child protected virtual function\n"); }

				public:
					int mem_public;
					int func_public() { printf("Child public func\n"); }
					virtual int vfunc_public() { printf("Child public virtual function\n"); }
				};
					;

					class GrandChild : public Child {

					public:
						GrandChild() { printf("GrandChild Constructor\n"); }
						~GrandChild() { printf("GrandChild Destructor\n"); }

					private:
						int GrandChildm_private;
						int func_private() { printf("GrandChild private func\n"); }
						virtual  int vfunc_private() { printf("GrandChild private virtual function\n"); }

					protected:
						int GrandChildm_protected;
						int func_protected() { printf("GrandChild protected func\n"); }
						virtual int vfunc_protected() { printf("GrandChild protected virtual function\n"); }

					public:
						int GrandChildm_public;
						int func_public() { printf("GrandChild public func\n"); }
						virtual int vfunc_public() { printf("GrandChild public virtual function\n"); }
					};



			class Sibling : public Parent {

			public:
				Sibling() { printf("Sibling Constructor\n"); }
				~Sibling() { printf("Sibling Destructor\n"); }

			private:
				int Siblingm_private;
				int func_private() { printf("Sibling private func\n"); }
				virtual  int vfunc_private() { printf("Sibling private virtual function\n"); }

			protected:
				int Siblingm_protected;
				int func_protected() { printf("Sibling protected func\n"); }
				virtual int vfunc_protected() { printf("Sibling protected virtual function\n"); }

			public:
				int Siblingm_public;
				int func_public() { printf("Sibling public func\n"); }
				virtual int vfunc_public() { printf("Sibling public virtual function\n"); }
			};
				;

				class Niece : public Sibling {

				public:
					Niece() { printf("Niece Constructor\n"); }
					~Niece() { printf("Niece Destructor\n"); }

				private:
					int mem_private;
					int func_private() { printf("Niece private func\n"); }
					virtual  int vfunc_private() { printf("Niece private virtual function\n"); }

				protected:
					int mem_protected;
					int func_protected() { printf("Niece protected func\n"); }
					virtual int vfunc_protected() { printf("Niece protected virtual function\n"); }

				public:
					int mem_public;
					int func_public() { printf("Niece public func\n"); }
					virtual int vfunc_public() { printf("Niece public virtual function\n"); }
				};



		class Uncle : public GrandParent {

		public:
			Uncle() { printf("Uncle Constructor\n"); }
			~Uncle() { printf("Uncle Destructor\n"); }

		private:
			int mem_private;
			int func_private() { printf("Uncle private func\n"); }
			virtual  int vfunc_private() { printf("Uncle private virtual function\n"); }

		protected:
			int mem_protected;
			int func_protected() { printf("Uncle protected func\n"); }
			virtual int vfunc_protected() { printf("Uncle protected virtual function\n"); }

		public:
			int mem_public;
			int func_public() { printf("Uncle public func\n"); }
			virtual int vfunc_public() { printf("Uncle public virtual function\n"); }
		};
			;

			class Cousin : public Uncle {

			public:
				Cousin() { printf("Cousin Constructor\n"); }
				~Cousin() { printf("Cousin Destructor\n"); }

			private:
				int mem_private;
				int func_private() { printf("Cousin private func\n"); }
				virtual  int vfunc_private() { printf("Cousin private virtual function\n"); }

			protected:
				int mem_protected;
				int func_protected() { printf("Cousin protected func\n"); }
				virtual int vfunc_protected() { printf("Cousin protected virtual function\n"); }

			public:
				int mem_public;
				int func_public() { printf("Cousin public func\n"); }
				virtual int vfunc_public() { printf("Cousin public virtual function\n"); }
			};


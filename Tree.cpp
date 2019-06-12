#include <iostream>
using std::cout;
using std::endl;

#include "Tree.hpp"
using namespace  ariel;

          int ans=0;
	  int sum=0;
          //function that will help us in insert function.
	  //check's if the tree is empty   	
          int ariel::Tree::isempty()
          {
	     return (Troot==NULL);
	  }

          //insert new node to the tree, if the tree is empty we will create
	  //new one, else we will insert the tree by the bst rulls.
          void ariel::Tree::insert(int key)
          {
		
        	tree_node *p = new tree_node;
        	tree_node *parent;
        	p->data=key;
        	p->left=NULL;
        	p->right=NULL;
        	parent=NULL;
        	if(isempty())
		Troot=p;
         	else
         	{
		tree_node *ptr;
		ptr=Troot;
		while(ptr!=NULL)
		{
			if(key==ptr->data)
                {
                        throw  "error";
                }

			parent=ptr;
			if(key>ptr->data)		
				ptr=ptr->right;
			else
				ptr=ptr->left;
		}	
		if(key<parent->data)
		{
			parent->left=p;
		}
		
		else
			parent->right=p;
	        }
           }
     	         
  	  void ariel::Tree::inorder_print(tree_node *ptr)
  	  {
  	    if(ptr!=NULL)
	    {
		inorder_print(ptr->left);
		cout<<"  "<<ptr->data<<"     ";
		inorder_print(ptr->right);
	    }
           }
          
          void ariel::Tree::print()
	  {
	      inorder_print(Troot);
	  }

	  bool ariel::Tree::containsHelp(tree_node *ptr,int key)
	  {
	     
             if(ptr==NULL)
             {
		 return false;
	     }
             if(ptr->data == key)
	     {
		 return true;
	     }	     
	     else if(ptr->data < key )
	     {
                 ptr=ptr->right;
                 return  containsHelp(ptr,key);  
	     } 
	     else
	     {
		 ptr=ptr->left;
                 return  containsHelp(ptr,key);
	     }
	    return false;
	  }

          bool ariel::Tree::contains(int key)
          {
		
	        tree_node *ptr;
                ptr=Troot;
                return  containsHelp(ptr,key);
	  }	

	  int ariel::Tree::root()
          {
            if(Troot==NULL)
	    {
		    return -1000;
	    }
		    
	    else 
	    return Troot->data;
	  }
	  int ariel::Tree::parentHelp(tree_node * ptr,int key)
	  {
            
	    if(ptr->data==key)
	    {
		
            }
		  
	    if(ptr->right->data==key || ptr->left->data==key)
	    {
		 return ptr->data; 
	    } 
	    else if(key < ptr->data) 
	    {
		 ptr=ptr->left;
		 return parentHelp(ptr,key);
	    }
            else
	    {
		 ptr=ptr->right;
		 return parentHelp(ptr,key);
	    }
	       
	  }
          
          int ariel::Tree::parent(int key)
          {
	         tree_node *ptr;
                 ptr=Troot;
		 return parentHelp(ptr,key);
	  }

         
	  int ariel::Tree::leftHelp(tree_node *ptr,int key)
	  {
            
	    if(ptr->data == key && ptr->left!=NULL)
	    {
               return ptr->left->data;
	    }
	    else if(key < ptr->data && ptr->left !=NULL )
	    {
	       ptr = ptr->left;
	       return leftHelp(ptr,key);
	    }
	    else 
	    {
		    if(ptr->right != NULL)
		    {
                          ptr = ptr->right;
                    return leftHelp(ptr,key);

		    } 
                 
            }
	    throw "key not exit !";
	   
	  }
 
          int ariel::Tree::left(int key)
	  {
               tree_node *ptr;
               ptr=Troot;
	       return leftHelp(ptr,key);
	  }	  


          
          int ariel::Tree::rightHelp(tree_node *ptr,int key)
          {

            if(ptr->data == key && ptr->right!=NULL)
            {
               return ptr->right->data;
            }
            else if(key < ptr->data && ptr->left !=NULL )
            {
               ptr = ptr->left;
               return rightHelp(ptr,key);
            }
            else
            {
                    if(ptr->right != NULL)
                    {
                          ptr = ptr->right;
                    return rightHelp(ptr,key);

                    }

            }
            throw "key not exit !";

          }

	  int ariel::Tree::right(int key)
	  {

	       tree_node *ptr;
               ptr=Troot;
               return rightHelp(ptr,key);
	  }
	  int ariel::Tree::sizeHelp(tree_node *ptr)
          {
		if(ptr == NULL)
		
			return 0;
		
		else 
			return (sizeHelp(ptr->left) + 1 + sizeHelp(ptr->right));
	  }
	 
        int ariel::Tree::size()
        {
		tree_node *ptr;
                ptr=Troot;
		return sizeHelp(ptr);

	}
        
    int ariel::Tree::minHelp(tree_node *ptr)
        {
		if(ptr->left == NULL)
		{
			return ptr->data;
		}
		ptr=ptr->left;
		return minHelp(ptr);
	}
        int  ariel::Tree::min(tree_node *ptr)
        {
              
	       return minHelp(ptr);

	}
      

    void ariel::Tree::removeHelp(tree_node *ptr,int key)
        { 
	     while(ans==0)
	     {
	   
           if(ptr->data == key)
	      {
              if(ptr->left == NULL && ptr->right == NULL)
	      {
		      ptr=NULL;
					delete ptr;
		      ans=1;
		      return print();
	      }
	      if(ptr->left == NULL && ptr->right != NULL)
	      {
		      ptr=ptr->right;
		      ptr->right=NULL;
					delete ptr->right;
		      ans=1;
	      }
	      if(ptr->left !=NULL && ptr->right == NULL)
	      {
		      ptr=ptr->left;
		      ptr->left=NULL;
					delete ptr->left;
		      ans=1;
	      }
	      if(ptr->left != NULL && ptr->right != NULL)
	      {

		    tree_node* temp = ptr; 
 
           ptr->data=min(ptr);
		    
		    return removeHelp(ptr,key);
	
	      }
                 
	      
	   }
	   else  if(ptr->data < key && ptr->left != NULL )
	   {
		   ptr=ptr->left;
                   		   
		   return removeHelp(ptr,key);
	   }
	   else if(ptr->right != NULL)
	   {
		   ptr=ptr->right;
		   
		   return removeHelp(ptr,key);
	   }
	   else throw "key not exit !";
	    
	   }
	}
          void ariel::Tree::remove(int key)
          {
               tree_node *ptr;
               ptr=Troot;
	         return removeHelp(ptr,key);

	  }

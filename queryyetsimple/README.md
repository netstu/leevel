

## is_object

错误的用法

~~~
value instanceof foo
~~~

to 

~~~
is_object(value) && value instanceof foo;
~~~

## is_empty

错误的用法

~~~
let arr = [1, 2]

if !(empty arr[2]) {
    
}
~~~

to 

~~~
let arr = [1, 2]

if isset arr[2] && arr[2] {
    
}
~~~

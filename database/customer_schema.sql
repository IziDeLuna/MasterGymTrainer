drop table if exists customers;
create table customers (
	cid integer primary key not null,
	firstname text not null,
	lastname text not null, 
	email text, 
	phone_number integer,
);
drop table if exists trainers;
create table trainers (
	tid integer primary key autoincrement not null,
	level integer,
	firstname text not null,
	lastname text not null,	
);



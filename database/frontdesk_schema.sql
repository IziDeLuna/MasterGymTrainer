drop table if exists frontdesk;
create table frontdesk (
	username text primary key not null,
	level integer,
)
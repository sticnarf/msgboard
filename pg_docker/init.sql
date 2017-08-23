CREATE TABLE "public"."users" (
    "id" serial,
    "username" text NOT NULL,
    "password_digest" text NOT NULL,
    "salt" text NOT NULL,
    PRIMARY KEY ("id"),
    UNIQUE ("username")
);

CREATE TABLE "public"."messages" (
    "id" serial,
    "user_id" integer NOT NULL,
    "content" text,
    "created_at" timestamp without time zone NOT NULL,
    PRIMARY KEY ("id"),
    FOREIGN KEY ("user_id") REFERENCES "public"."users"("id") ON DELETE CASCADE
);

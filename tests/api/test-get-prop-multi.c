/*
 *  duk_get_prop_multi()
 */

static duk_ret_t test_basic(duk_context *ctx) {
	duk_int_t my_int;

	duk_eval_string(ctx, "({ undefinedValue: void 0, \n"
	                     "   nullValue: null, \n"
	                     "   falseValue: false, \n"
	                     "   trueValue: true, \n"
	                     "   integerValue: -321, \n"
	                     "   numberValue: 123.4, \n"
	                     "   stringValue: 'foo bar' })");

	my_int = 123;
	duk_get_prop_multi(ctx, -1, "integerValue:d", &my_int);
	printf("my_int: %ld\n", (long) my_int);

	printf("final top: %ld\n", (long) duk_get_top(ctx));
	return 0;
}

/* FIXME: missing property */
/* FIXME: NULL value pointer */
/* FIXME: invalid character */
/* FIXME: missing colon */

void test(duk_context *ctx) {
	TEST_SAFE_CALL(test_basic);
}

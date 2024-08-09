#define tst_head(x)						\
	do {							\
		printk("********** %s START  *********\n", x);	\
	} while (0);

#define tst_chk(x, fmt, ...)						\
	do {								\
		if (!(x)) {						\
			printk("*** %s %d " fmt "***\n", __func__, __LINE__, \
			       __VA_ARGS__);				\
			return -EINVAL;					\
		} else {						\
			printk("***** %s %d passed ****\n", __func__, __LINE__); \
		} } while (0);

static int test_pinctrl_attributes(struct scmi_protocol_handle *handle)
{
	int ret;
	char name[SCMI_MAX_STR_SIZE];
	unsigned n_elems;
	tst_head("scmi_pinctrl_attributes");

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 1, NULL, &n_elems);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 1, NULL, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 0, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 12, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 999, name, &n_elems);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_attributes(handle, PIN_TYPE, 0, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, PIN_TYPE, 1, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, PIN_TYPE, 12, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, PIN_TYPE, 999, name, &n_elems);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_attributes(handle, FUNCTION_TYPE, 1, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, FUNCTION_TYPE, 12, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, FUNCTION_TYPE, 999, name, &n_elems);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	return 0;
}

static void show_array(unsigned *array, uint8_t size)
{
	int i;
	for (i = 0; i < size; i++) {
		printk("%d ", array[i]);
	}
	printk("\n");
}

static int test_pinctrl_list_assoc_short(struct scmi_protocol_handle *handle)
{
	int ret;
	unsigned array[100];

	printk(" === %s %d\n", __func__, __LINE__);

	memset(array, 0, 100 * sizeof(uint16_t));
	tst_head("scmi_pinctrl_list_associations");

	ret = scmi_pinctrl_list_associations(handle, 1, GROUP_TYPE, 100, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_list_associations(handle, 1, GROUP_TYPE, 0, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_list_associations(handle, 1, GROUP_TYPE, 0, array);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_list_associations(handle, 1, PIN_TYPE, 0, array);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 0, GROUP_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	return 0;
}

static int test_pinctrl_list_assoc(struct scmi_protocol_handle *handle)
{
	int ret;
	unsigned array[100];

	printk(" === %s %d\n", __func__, __LINE__);

	memset(array, 0, 100 * sizeof(uint16_t));
	tst_head("scmi_pinctrl_list_associations");

	ret = scmi_pinctrl_list_associations(handle, 1, GROUP_TYPE, 100, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_list_associations(handle, 1, GROUP_TYPE, 0, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_list_associations(handle, 1, GROUP_TYPE, 0, array);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_list_associations(handle, 1, PIN_TYPE, 0, array);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 0, GROUP_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 12, GROUP_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 19, GROUP_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 24, GROUP_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 999, GROUP_TYPE, 100, array);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 0, FUNCTION_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 12, FUNCTION_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 19, FUNCTION_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 24, FUNCTION_TYPE, 100, array);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	show_array(array, 10);

	memset(array, 0, 100 * sizeof(uint16_t));
	ret = scmi_pinctrl_list_associations(handle, 999, FUNCTION_TYPE, 100, array);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	return 0;
}

static int grp_fnc_cnt(struct scmi_protocol_handle *handle)
{
	struct scmi_protocol_handle handle2;
	int ret;

	memcpy(&handle2, handle, sizeof(handle2));
	tst_head("scmi_pinctrl_get_groups_count");
	ret = scmi_pinctrl_count_get(handle, GROUP_TYPE);
	tst_chk(ret == 353, "Unexpected ret %d", ret);

	handle2.set_priv(&handle2, NULL, 1);
	ret = scmi_pinctrl_count_get(&handle2, GROUP_TYPE);
	tst_chk(ret == -19, "Unexpected ret %d", ret);

	tst_head("scmi_pinctrl_get_functions_count");
	ret = scmi_pinctrl_count_get(handle, FUNCTION_TYPE);
	tst_chk(ret == 58, "Unexpected ret %d", ret);

	handle2.set_priv(&handle2, NULL, 1);
	ret = scmi_pinctrl_count_get(&handle2, FUNCTION_TYPE);
	tst_chk(ret == -19, "Unexpected ret %d", ret);
	return 0;
}

static int test_pinctrl_basic_calls(struct scmi_protocol_handle *handle)
{
	int ret;
	const char *name;
	char name_s[SCMI_MAX_STR_SIZE];
	unsigned n_elems;

	tst_head("scmi_pinctl_name_get");
	ret = scmi_pinctrl_name_get(handle, 1, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	tst_head("scmi_pinctl_name_get");
	ret = scmi_pinctrl_name_get(handle, 0, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 1, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 0, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 1, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 0, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 1, NULL, &n_elems);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 1, NULL, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_attributes(handle, GROUP_TYPE, 0, name_s, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name_s, n_elems);

	ret = scmi_pinctrl_attributes(handle, PIN_TYPE, 0, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = scmi_pinctrl_attributes(handle, FUNCTION_TYPE, 1, name, &n_elems);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s, nelems = %d\n", __LINE__, name, n_elems);

	ret = test_pinctrl_list_assoc_short(handle);
	if (ret)
		return ret;
	return 0;
}

static int scmi_pinctrl_protocol_deinit(const struct scmi_protocol_handle *ph);

static int run_tests(const struct scmi_protocol_handle *chandle)
{
	int ret;
	u32 version;

	struct scmi_protocol_handle *handle = (struct scmi_protocol_handle *)chandle;
	struct scmi_pinctrl_info pi;
	// scmi_pinctrl_attributes_get
	tst_head("scmi_pinctrl_attributes_get");
	ret = scmi_pinctrl_attributes_get(handle, &pi);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("pi->nr_functions = %d, nr->groups=%d nr->pins = %d\n",
	       pi.nr_functions, pi.nr_groups, pi.nr_pins);
	tst_chk(pi.nr_functions == 83, "Functions exp 58, got %d", pi.nr_functions);
	tst_chk(pi.nr_groups == 65,"Groups exp 353, got %d", pi.nr_groups);
	tst_chk(pi.nr_pins == 65,"Pins exp 199, got %d", pi.nr_pins);
//
//	ret = scmi_pinctrl_attributes_get(handle, NULL);
//	tst_chk(ret == -EINVAL, "Unexpected ret %d", ret);

	tst_head("scmi_version_get");
	handle->xops->version_get(handle, &version);
	tst_chk(version == 0x10000, "Wrong version %x", version);

	ret = test_pinctrl_basic_calls(handle);
	if (ret)
		return ret;


	ret = scmi_pinctrl_protocol_deinit(chandle);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	return 0;
}

static int run_tests_main(const struct scmi_protocol_handle *chandle)
{
	int ret;
	u32 version;
	const char *name;

	struct scmi_protocol_handle *handle = (struct scmi_protocol_handle *)chandle;
	struct scmi_pinctrl_info pi;
	// scmi_pinctrl_attributes_get
	tst_head("scmi_pinctrl_attributes_get");
	ret = scmi_pinctrl_attributes_get(handle, &pi);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("pi->nr_functions = %d, nr->groups=%d nr->pins = %d\n",
	       pi.nr_functions, pi.nr_groups, pi.nr_pins);
	tst_chk(pi.nr_functions == 1, "Functions exp 58, got %d", pi.nr_functions);
	tst_chk(pi.nr_groups == 1,"Groups exp 353, got %d", pi.nr_groups);
	tst_chk(pi.nr_pins == 2,"Pins exp 199, got %d", pi.nr_pins);
//
//	ret = scmi_pinctrl_attributes_get(handle, NULL);
//	tst_chk(ret == -EINVAL, "Unexpected ret %d", ret);

	tst_head("scmi_version_get");
	handle->xops->version_get(handle, &version);
	tst_chk(version == 0x10000, "Wrong version %x", version);

	tst_head("scmi_pinctl_name_get");
	ret = scmi_pinctrl_name_get(handle, 1, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	tst_head("scmi_pinctl_name_get");
	ret = scmi_pinctrl_name_get(handle, 0, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 15, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 192, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 999, PIN_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_name_get(handle, 1, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 15, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 192, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 999, GROUP_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_name_get(handle, 1, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 0, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 15, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("%d name = %s\n", __LINE__, name);
	kfree(name);

	ret = scmi_pinctrl_name_get(handle, 192, FUNCTION_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_name_get(handle, 1, 23, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = scmi_pinctrl_name_get(handle, 1, PIN_TYPE, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = test_pinctrl_attributes(handle);
	if (ret)
		return ret;

	ret = test_pinctrl_list_assoc(handle);
	if (ret)
		return ret;

	ret = grp_fnc_cnt(handle);
	if (ret)
		return ret;

	ret = scmi_pinctrl_protocol_deinit(chandle);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	return 0;
}


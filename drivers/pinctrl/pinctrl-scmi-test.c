
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

#define tst_chknf(x, fmt, ...)						\
	do {								\
		if (!(x)) {						\
			printk("*** %s %d " fmt "***\n", __func__, __LINE__, \
			       __VA_ARGS__);				\
		} else {						\
			printk("***** %s %d passed ****\n", __func__, __LINE__); \
		} } while (0);

static int conf_tests(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	const struct scmi_protocol_handle *handle = pmx->ph;
        unsigned long lconfig;
	unsigned long config;
	u8 ltype;
	int ret;
	tst_head("ops->config_get");
	//TODO impleme
	lconfig = 1;
	ltype = 1;
	/* ret = pinctrl_ops->config_set(handle, 0, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chknf(ret == 0, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 0, PIN_TYPE, 1, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chknf(lconfig == 1, "Unexpected config %ld", lconfig); */

	/* lconfig = 2000; */
	/* ltype = 10; */
	/* ret = pinctrl_ops->config_set(handle, 0, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chknf(ret == 0, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 0, PIN_TYPE, 10, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chk(lconfig == 2000, "Unexpected config %ld", lconfig); */

	/* lconfig = 1; */
	/* ltype = 230; */
	/* ret = pinctrl_ops->config_set(handle, 0, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */

	/* /\*drive strength *\/ */
	/* lconfig = 3; */
	/* ltype = 10; */
	/* ret = pinctrl_ops->config_set(handle, 0, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 0, PIN_TYPE, 10, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chk(lconfig == 3, "Unexpected config %ld", lconfig); */

	/* /\*bias-pull-up *\/ */
	/* lconfig = 3; */
	/* ltype = 2; */
	/* ret = pinctrl_ops->config_set(handle, 0, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 0, PIN_TYPE, 4, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chk(lconfig == 3, "Unexpected config %ld", lconfig); */

	/* /\*power-source *\/ */
	/* lconfig = 3; */
	/* ltype = 19; */
	/* ret = pinctrl_ops->config_set(handle, 1, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 1, PIN_TYPE, 19, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chk(lconfig == 3, "Unexpected config %ld", lconfig); */

	/* /\*bias-pull-up *\/ */
	/* lconfig = 3; */
	/* ltype = 4; */
	/* ret = pinctrl_ops->config_set(handle, 24, PIN_TYPE, 1, &ltype, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 24, PIN_TYPE, 4, &lconfig); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chk(lconfig == 3, "Unexpected config %ld", lconfig); */

	/* /\*bias-pull-up *\/ */
	/* lconfig = 3; */
	/* ltype = 4; */
	/* ret = pinctrl_ops->config_set(handle, 999, PIN_TYPE, 1, &ltype, */
	/* 			      &lconfig); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(handle, 999, PIN_TYPE, 4, &lconfig); */
	/* tst_chknf(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chknf(lconfig == 3, "Unexpected config %ld", lconfig); */

	/* ret = pinctrl_ops->config_get(handle, 1, PIN_TYPE, 0, &lconfig); */
	/* tst_chknf(ret == 0, "Unexpected ret %d", ret); */
	/* tst_chknf(lconfig == 3, "Unexpected config %ld", lconfig); */

	/* ret = pinctrl_ops->config_get(handle, 1, PIN_TYPE, 230, &lconfig); */
	/* tst_chk(ret == -5, "Unexpected ret %d", ret); */

	/* /\*bias-bus-hold *\/ */
	/* ret = pinctrl_ops->config_get(handle, 1, PIN_TYPE, 1, NULL); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	/* ret = pinctrl_ops->config_get(NULL, 1, PIN_TYPE, 230, &lconfig); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	tst_head("pinctrl_scmi_pinconf_get/set");

	config = pinconf_to_config_packed(1, 10);
	ret = pinctrl_scmi_pinconf_set(pmx->pctldev, 0, &config, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	config = pinconf_to_config_packed(1, 10);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 0, &config);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	tst_chk(pinconf_to_config_argument(config) == 10, "Unexpected config %ld", config);

	config = pinconf_to_config_packed(1, 0);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 1, &config);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	tst_chk(pinconf_to_config_argument(config) == 10, "Unexpected config %ld", config);

	config = pinconf_to_config_packed(1, 10);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 24, &config);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	tst_chk(pinconf_to_config_argument(config) == 10, "Unexpected config %ld", config);

	config = pinconf_to_config_packed(1, 10);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 999, &config);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	config = pinconf_to_config_packed(1, 10);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 1, &config);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	tst_chk(pinconf_to_config_argument(config) == 10,
		"Unexpected config %ld", config);

	config = pinconf_to_config_packed(999, 0);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 1, &config);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	config = pinconf_to_config_packed(1, 10);
	ret = pinctrl_scmi_pinconf_get(pmx->pctldev, 1, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	/* config = 999; /\*bias-bus-hold *\/ */
	/* ret = pinctrl_scmi_pinconf_get(NULL, 1, NULL); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	config = pinconf_to_config_packed(10, 0);
	ret = pinctrl_scmi_pinconf_set(pmx->pctldev, 0, &config, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	tst_head("ops->get/set_config_group");
	config = pinconf_to_config_packed(1, 0);
	ret = pinctrl_scmi_pinconf_group_set(pmx->pctldev, 0, &config, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	config = pinconf_to_config_packed(999, 0);
	ret = pinctrl_scmi_pinconf_group_set(pmx->pctldev, 15, &config, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	config = pinconf_to_config_packed(10, 10);
	ret = pinctrl_scmi_pinconf_group_set(pmx->pctldev, 15, &config, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	config = pinconf_to_config_packed(10, 0);
	ret = pinctrl_scmi_pinconf_group_get(pmx->pctldev, 15, &config);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	tst_chk(pinconf_to_config_argument(config) == 10,
		"Unexpected config %ld", config);

	unsigned long configs[7];
	int i;
	for (i = 1; i< 8; i++)
	{
		configs[i-1] = pinconf_to_config_packed(i, i+5);
	}
	ret = pinctrl_scmi_pinconf_set(pmx->pctldev, 1 , configs, 7);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	u8 config_types[20];
	unsigned long config_values[20];

	/* ret = pinctrl_ops->config_get_all(handle, 1, PIN_TYPE, 20, config_types, config_values); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* for (i = 0; i < 20; i++) { */
	/* 	printk("%s %d: types [ %d] = %d, val = %ld\n", __func__, __LINE__, */
	/* 	       i, config_types[i], config_values[i]); */
	/* } */

	return 0;
}

static int gr_getinfo_test(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	const struct scmi_protocol_handle *handle = pmx->ph;
	int ret;
	const char *name;
	tst_head("ops->get_group_name");

	ret = pinctrl_ops->name_get(handle, 0, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 0, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 15, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 15, GROUP_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 999, GROUP_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_ops->name_get(handle, 990, GROUP_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	name = pinctrl_scmi_get_group_name(pmx->pctldev, 0);
	tst_chk(name != 0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_group_name(pmx->pctldev, 0);
	tst_chk(name !=0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_group_name(pmx->pctldev, 14);
	tst_chk(name != 0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_group_name(pmx->pctldev, 14);
	tst_chk(name !=0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_group_name(pmx->pctldev, 999);
	tst_chk(name == 0, "Unexpected name %d", -1);

	name = pinctrl_scmi_get_group_name(pmx->pctldev, 999);
	tst_chk(name == 0, "Unexpected name %d", -1);

	/* name = pinctrl_scmi_get_group_name(NULL, 999); */
	/* tst_chk(name == 0, "Unexpected name %d", -1); */

	return 0;
}

static int fn_getinfo_test(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	const struct scmi_protocol_handle *handle = pmx->ph;
	int ret;
	const char *name;
	tst_head("ops->get_function_name");

	ret = pinctrl_ops->name_get(handle, 0, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 0, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 15, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 15, FUNCTION_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 999, FUNCTION_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);
	printk("name = %s", name);

	ret = pinctrl_ops->name_get(handle, 990, FUNCTION_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);
	printk("name = %s", name);

	name = pinctrl_scmi_get_function_name(pmx->pctldev, 0);
	tst_chk(name != 0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_function_name(pmx->pctldev, 0);
	tst_chk(name !=0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_function_name(pmx->pctldev, 14);
	tst_chk(name != 0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_function_name(pmx->pctldev, 14);
	tst_chk(name !=0, "Unexpected name %d", -1);
	printk("name = %s", name);

	name = pinctrl_scmi_get_function_name(pmx->pctldev, 999);
	tst_chk(name == 0, "Unexpected name %d", -1);

	name = pinctrl_scmi_get_function_name(pmx->pctldev, 999);
	tst_chk(name == 0, "Unexpected name %d", -1);

	/* name = pinctrl_scmi_get_function_name(NULL, 999); */
	/* tst_chk(name == 0, "Unexpected name %d", -1); */

	return 0;
}

static void show_array(const unsigned *array, unsigned size)
{
	int i;
	for (i = 0; i < size; i++) {
		printk("%d ", array[i]);
	}
	printk("\n");
}

static int gr_get_pins_test(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	const struct scmi_protocol_handle *handle = pmx->ph;
	int ret;
	unsigned num_pins;
	const unsigned *pins;
	tst_head("ops->group_pins_get");

	ret = pinctrl_ops->group_pins_get(handle, 0, &pins, &num_pins);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_pins = %d\n", num_pins);
	show_array(pins, num_pins);

	ret = pinctrl_ops->group_pins_get(handle, 15, &pins, &num_pins);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_pins = %d\n", num_pins);
	show_array(pins, num_pins);

	ret = pinctrl_ops->group_pins_get(handle, 999, &pins, &num_pins);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_ops->group_pins_get(handle, 999, NULL, &num_pins);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_get_group_pins(pmx->pctldev, 0, &pins, &num_pins);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_pins = %d\n", num_pins);
	show_array(pins, num_pins);

	ret = pinctrl_scmi_get_group_pins(pmx->pctldev, 0, &pins, &num_pins);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_pins = %d\n", num_pins);
	show_array(pins, num_pins);

	ret = pinctrl_scmi_get_group_pins(pmx->pctldev, 15, &pins, &num_pins);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_pins = %d\n", num_pins);
	show_array(pins, num_pins);

	ret = pinctrl_scmi_get_group_pins(pmx->pctldev, 999, &pins, &num_pins);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_get_group_pins(pmx->pctldev, 0, NULL, &num_pins);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_get_group_pins(pmx->pctldev, 0, &pins, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	/* ret = pinctrl_scmi_get_group_pins(NULL, 0, NULL, &num_pins); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	return 0;
}

static void show_carray(const char **array, unsigned size)
{
	int i;
	for (i = 0; i < size; i++) {
		printk("%s ", array[i]);
	}
	printk("\n");
}

static int fn_get_groups_test(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	const struct scmi_protocol_handle *handle = pmx->ph;
	int ret;
	const unsigned *group_ids;
	const char **groups;
	const char * const **pgroups = (const char * const **)&groups;
	unsigned num_groups;
	tst_head("ops->function_groups_get");

	ret = pinctrl_ops->function_groups_get(handle, 0, &num_groups, &group_ids);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_groups = %d\n", num_groups);
	show_array(group_ids, num_groups);

	ret = pinctrl_ops->function_groups_get(handle, 15, &num_groups, &group_ids);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_groups = %d\n", num_groups);
	show_array(group_ids, num_groups);

	ret = pinctrl_ops->function_groups_get(handle, 999, &num_groups, &group_ids);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_get_function_groups(pmx->pctldev, 0, pgroups, &num_groups);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_groups = %d\n", num_groups);
	show_carray(groups, num_groups);

	ret = pinctrl_scmi_get_function_groups(pmx->pctldev, 15, pgroups, &num_groups);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("num_groups = %d\n", num_groups);
	show_carray(groups, num_groups);

	ret = pinctrl_scmi_get_function_groups(pmx->pctldev, 999, pgroups, &num_groups);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	return 0;
}


static int req_free_test(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	int ret;
	tst_head("free -> release");

	ret = pinctrl_scmi_request(pmx->pctldev, 10);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_free(pmx->pctldev, 10);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_request(pmx->pctldev, 11);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_request(pmx->pctldev, 11);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_free(pmx->pctldev, 11);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_free(pmx->pctldev, 11);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_request(pmx->pctldev, 999);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_free(pmx->pctldev, 999);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	return 0;
}

static int set_mux_test(struct pinctrl_dev *pctldev)
{
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	int ret;
	const struct scmi_protocol_handle *handle = pmx->ph;

	tst_head("set mux");

	ret = pinctrl_ops->mux_set(handle, 0, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_ops->mux_set(handle, 15, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_ops->mux_set(handle, 1, 15);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_ops->mux_set(handle, 999, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_ops->mux_set(handle, 0, 999);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_func_set_mux(pmx->pctldev, 0, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_func_set_mux(pmx->pctldev, 1, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_func_set_mux(pmx->pctldev, 15, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_func_set_mux(pmx->pctldev, 1, 15);
	tst_chk(ret == 0, "Unexpected ret %d", ret);

	ret = pinctrl_scmi_func_set_mux(pmx->pctldev, 0, 999);
	tst_chk(ret == -22, "Unexpected ret %d", ret);
	ret = pinctrl_scmi_func_set_mux(pmx->pctldev, 999, 1);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	/* ret = pinctrl_scmi_func_set_mux(NULL, 0, 1); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	return 0;
}

static void show_pinarray(const struct pinctrl_pin_desc *array, unsigned size)
{
	int i;
	for (i = 0; i < size; i++) {
		printk("pin[%d]=%s ", array[i].number, array[i].name);
	}
	printk("\n");
}


static int get_pins_tests(struct pinctrl_dev *pctldev)
{
	int ret;
	unsigned nr_pins;
	struct scmi_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
	struct scmi_protocol_handle *handle = pmx->ph;
	const char *name;
	const struct pinctrl_pin_desc *pins;
	tst_head("get pins");

	ret = pinctrl_ops->name_get(handle, 0, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("Name = %s\n", name);

	ret = pinctrl_ops->name_get(handle, 15, PIN_TYPE, &name);
	tst_chk(ret == 0, "Unexpected ret %d", ret);
	printk("Name = %s\n", name);

	ret = pinctrl_ops->name_get(handle, 999, PIN_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_ops->name_get(handle, 12, PIN_TYPE, NULL);
	tst_chk(ret == -22, "Unexpected ret %d", ret);

	ret = pinctrl_ops->name_get(NULL, 1, PIN_TYPE, &name);
	tst_chk(ret == -22, "Unexpected ret %d", ret);
	//TODO amoi implement
	/* ret = pinctrl_scmi_get_pins(pmx, &nr_pins, &pins); */
	/* tst_chk(ret == 0, "Unexpected ret %d", ret); */
	/* show_pinarray(pins, 20); */
	/* printk("nr_pins = %d\n", nr_pins); */

	/* ret = pinctrl_scmi_get_pins(pmx, NULL, &pins); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	/* ret = pinctrl_scmi_get_pins(pmx, &nr_pins, NULL); */
	/* tst_chk(ret == -22, "Unexpected ret %d", ret); */

	return 0;
}

static int run_tests(struct pinctrl_dev *pctldev)
{
	int ret;

	ret = gr_getinfo_test(pctldev);
	if (ret)
		return ret;

	ret = fn_getinfo_test(pctldev);
	if (ret)
		return ret;

	ret = gr_get_pins_test(pctldev);
	if (ret)
		return ret;

	ret = fn_get_groups_test(pctldev);
	if (ret)
		return ret;

	ret = req_free_test(pctldev);
	if (ret)
		return ret;

	ret = conf_tests(pctldev);
	if (ret)
		return ret;

	ret = set_mux_test(pctldev);
	if (ret)
		return ret;

	ret = get_pins_tests(pctldev);
	if (ret)
		return ret;

	return 0;
}

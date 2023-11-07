

#ifndef __OAL_LIST_H__
#define __OAL_LIST_H__

/* ����ͷ�ļ����� */
#include "oal_types.h"
#include "oal_mm.h"
#include "oal_util.h"

/* �궨�� */
/* ��������ͷ��ʼ�� */
#define oal_list_head_init(_list_name)                                             \
    {                                                                              \
        (oal_list_entry_stru *)&(_list_name), (oal_list_entry_stru *)&(_list_name) \
    }

/* ���򴴽�����ͷ */
/*lint -e773*/
#define oal_list_create_head(_list_name) \
    oal_list_head_stru _list_name = oal_list_head_init(_list_name)

/* �����������ʹ��ʱ�������Ӵ����� */
#define oal_list_search_for_each(_list_pos, _list_head)                                              \
    for ((_list_pos) = (_list_head)->pst_next; (_list_pos) != (oal_list_entry_stru *)(_list_head); \
         (_list_pos) = (_list_pos)->pst_next)

/*
 * ��õ���������ָ���Ľڵ� ��һ������Ϊģ�������ṹ��ָ�룻 �ڶ�������Ϊ���������ݽṹ����������
 * ����������Ϊ���ݽṹ����ģ�������ṹ�������
 */
#define oal_list_get_entry(_list_ptr, _data_type, _data_member_list_name) \
    ((_data_type *)((int8_t *)(_list_ptr) - (oal_uint)(&((_data_type *)0)->_data_member_list_name))) /*lint -e(413)*/

/* ˫������ͷ��ʼ�� */
#define oal_dlist_head_init(_dlist_name) \
    {                                    \
        &(_dlist_name), &(_dlist_name)   \
    }

/* ����˫������ͷ */
/*lint -e773*/
#define oal_dlist_create_head(_dlist_name) \
    oal_dlist_head_stru _dlist_name = oal_dlist_head_init(_dlist_name)

/* ����˫������ʹ��ʱ�������Ӵ����� */
#define oal_dlist_search_for_each(_dlist_pos, _dilst_head) \
    for ((_dlist_pos) = (_dilst_head)->pst_next; (_dlist_pos) != (_dilst_head); (_dlist_pos) = (_dlist_pos)->pst_next)

/* ����˫�����������ɰ�ȫɾ��ĳ���ڵ� */
#define oal_dlist_search_for_each_safe(_dlist_pos, n, _dilst_head)                                    \
    for ((_dlist_pos) = (_dilst_head)->pst_next, (n) = (_dlist_pos)->pst_next; (_dlist_pos) != (_dilst_head); \
         (_dlist_pos) = (n), (n) = (_dlist_pos)->pst_next)

/* ����netbuf head�����е�netbuf��ע��1102device��netbuf�ǵ������� */
#define oal_netbuf_search_for_each(_netbuf_pos, _netbuf_head) \
    for ((_netbuf_pos) = (_netbuf_head)->next; (_netbuf_pos) != (oal_netbuf_stru *)(_netbuf_head); \
        (_netbuf_pos) = (_netbuf_pos)->next)

/* ����netbuf���������ɰ�ȫɾ��ĳ���ڵ� */
#define oal_netbuf_search_for_each_safe(_dlist_pos, n, _dilst_head) \
        for ((_dlist_pos) = (_dilst_head)->next, (n) = (_dlist_pos)->next; \
            (_dlist_pos) != (oal_netbuf_stru *)(_dilst_head); (_dlist_pos) = (n), (n) = (_dlist_pos)->next)
/*
 * ���˫��������ָ���Ľڵ� ��һ������Ϊģ�������ṹ��ָ�룻 �ڶ�������Ϊ���������ݽṹ����������
 * ����������Ϊ���ݽṹ����ģ�������ṹ�������
 */
#define oal_dlist_get_entry(_dlist_ptr, _data_type, _data_member_dlist_name) \
    ((_data_type *)((int8_t *)(_dlist_ptr) - (oal_uint)(&((_data_type *)0)->_data_member_dlist_name))) /*lint -e(413)*/

/* STRUCT���� */
typedef struct tag_oal_list_entry_stru {
    struct tag_oal_list_entry_stru *pst_next;
} oal_list_entry_stru;

typedef struct {
    struct tag_oal_list_entry_stru *pst_next;
    struct tag_oal_list_entry_stru *pst_prev;
} oal_list_head_stru;

typedef struct tag_oal_dlist_head_stru {
    struct tag_oal_dlist_head_stru *pst_next;
    struct tag_oal_dlist_head_stru *pst_prev;
} oal_dlist_head_stru;

/*
 * �� �� ��  : oal_list_init_head
 * ��������  : ��ʼ����������ͷ
 * �������  : pst_list_head: ��������ͷָ��
 */
OAL_STATIC OAL_INLINE void oal_list_init_head(oal_list_head_stru *pst_list_head)
{
    if (oal_unlikely(pst_list_head == NULL)) {
        oal_warn_on(1);
        return;
    }
    pst_list_head->pst_next = (oal_list_entry_stru *)pst_list_head;
    pst_list_head->pst_prev = (oal_list_entry_stru *)pst_list_head;
}

/*
 * �� �� ��  : oal_list_add
 * ��������  : �������ڵ���뵽������β��
 * �������  : pst_new: �¼���ڵ�ָ��
 *              pst_head: ����ͷ
 */
OAL_STATIC OAL_INLINE void oal_list_add(oal_list_entry_stru *pst_new,
                                        oal_list_head_stru *pst_head)
{
    oal_list_entry_stru *pst_tail = NULL;
    if (oal_unlikely((pst_new == NULL) || (pst_head == NULL))) {
        oal_warn_on(1);
        return;
    }
    pst_tail = pst_head->pst_prev;

    pst_tail->pst_next = pst_new;
    pst_new->pst_next = (oal_list_entry_stru *)pst_head;
    pst_head->pst_prev = pst_new;
}

/*
 * �� �� ��  : oal_list_delete_head
 * ��������  : ������ͷɾ��һ���ڵ㣬�������ͷţ����ж������Ƿ�Ϊ�գ���ע��
 * �������  : pst_head: ����ͷ
 * �� �� ֵ  : ��ɾ���Ľڵ�
 */
OAL_STATIC OAL_INLINE oal_list_entry_stru *oal_list_delete_head(oal_list_head_stru *pst_head)
{
    oal_list_entry_stru *pst_node = NULL;

    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return NULL;
    }

    if (pst_head->pst_next == (oal_list_entry_stru *)pst_head) {
        return OAL_PTR_NULL;
    }

    pst_node = pst_head->pst_next;
    pst_head->pst_next = pst_node->pst_next;

    if (pst_head->pst_next == (oal_list_entry_stru *)pst_head) {
        pst_head->pst_prev = pst_head->pst_next;
    }

    pst_node->pst_next = OAL_PTR_NULL;

    return pst_node;
}

/*
 * �� �� ��  : oal_list_jion
 * ��������  : ������2�ĵ��������������1�ĵ���������
 */
OAL_STATIC OAL_INLINE void oal_list_jion(oal_list_head_stru *pst_head1, oal_list_head_stru *pst_head2)
{
    oal_list_entry_stru *pst_list1_tail = NULL;
    oal_list_entry_stru *pst_list2_tail = NULL;

    if (oal_unlikely((pst_head1 == NULL) || (pst_head2 == NULL))) {
        oal_warn_on(1);
        return;
    }

    pst_list1_tail = pst_head1->pst_prev;
    pst_list2_tail = pst_head2->pst_prev;
    pst_list1_tail->pst_next = pst_head2->pst_next;
    pst_head1->pst_prev = pst_head2->pst_prev;
    pst_list2_tail->pst_next = (oal_list_entry_stru *)pst_head1;
}

/*
 * �� �� ��  : oal_dlist_is_empty
 * ��������  : �ж�һ�������Ƿ�Ϊ��
 * �������  : pst_head: ����ͷָ��
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 oal_list_is_empty(oal_list_head_stru *pst_head)
{
    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return OAL_FALSE;
    }
    return pst_head->pst_next == (oal_list_entry_stru *)pst_head;
}

/*
 * �� �� ��  : oal_dlist_init_head
 * ��������  : ������ʼ������
 * �������  : pst_list: ����ͷָ��
 */
OAL_STATIC OAL_INLINE void oal_dlist_init_head(oal_dlist_head_stru *pst_list)
{
    if (oal_unlikely(pst_list == NULL)) {
        oal_warn_on(1);
        return;
    }
    pst_list->pst_next = pst_list;
    pst_list->pst_prev = pst_list;
}

/*
 * �� �� ��  : oal_dlist_add
 * ��������  : �����ڵ�������
 * �������  : pst_new: �¼���ڵ�ָ��
 *             pst_prev: ����λ�õ�ǰһ���ڵ�ָ��
 *             pst_next: ����λ�õ���һ���ڵ�ָ��
 */
OAL_STATIC OAL_INLINE void oal_dlist_add(oal_dlist_head_stru *pst_new,
                                         oal_dlist_head_stru *pst_prev,
                                         oal_dlist_head_stru *pst_next)
{
    if (oal_unlikely((pst_new == NULL) || (pst_prev == NULL) || (pst_prev == NULL))) {
        oal_warn_on(1);
        return;
    }
    pst_next->pst_prev = pst_new;
    pst_new->pst_next = pst_next;
    pst_new->pst_prev = pst_prev;
    pst_prev->pst_next = pst_new;
}

/*
 * �� �� ��  : oal_dlist_delete
 * ��������  : ��������ָ��λ��ɾ��һ���ڵ�����
 * �������  : pst_prev: ɾ��λ�õ�ǰһ���ڵ�ָ��
 *             pst_next: ɾ��λ�õ���һ���ڵ�ָ��
 */
OAL_STATIC OAL_INLINE void oal_dlist_delete(oal_dlist_head_stru *pst_prev, oal_dlist_head_stru *pst_next)
{
    if (oal_unlikely((pst_prev == NULL) || (pst_next == NULL))) {
        oal_warn_on(1);
        return;
    }
    pst_next->pst_prev = pst_prev;
    pst_prev->pst_next = pst_next;
}

/*
 * �� �� ��  : oal_dlist_is_empty
 * ��������  : �ж�һ�������Ƿ�Ϊ��
 * �������  : pst_head: ����ͷָ��
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 oal_dlist_is_empty(oal_dlist_head_stru *pst_head)
{
    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return OAL_TRUE;
    }
    if (oal_any_null_ptr2(pst_head->pst_next, pst_head->pst_prev)) {
        return OAL_TRUE;
    }

    return pst_head->pst_next == pst_head;
}

/*
 * �� �� ��  : oal_dlist_add_head
 * ��������  : ������ͷ������ڵ�
 * �������  : pst_new: Ҫ������½ڵ�
 *             pst_head: ����ͷָ��
 */
OAL_STATIC OAL_INLINE void oal_dlist_add_head(oal_dlist_head_stru *pst_new, oal_dlist_head_stru *pst_head)
{
    oal_dlist_add(pst_new, pst_head, pst_head->pst_next);
}

/*
 * �� �� ��  : oal_dlist_add_tail
 * ��������  : ������β������ڵ�
 * �������  : pst_new: Ҫ������½ڵ�
 *             pst_head: ����ͷָ��
 */
OAL_STATIC OAL_INLINE void oal_dlist_add_tail(oal_dlist_head_stru *pst_new, oal_dlist_head_stru *pst_head)
{
    oal_dlist_add(pst_new, pst_head->pst_prev, pst_head);
}

/*
 * �� �� ��  : oal_dlist_delete_entry
 * ��������  : ɾ�������е�ָ���ڵ�,�������ͷţ����ж������Ƿ�Ϊ�գ���ע��
 * �������  : pst_entry: ��Ҫɾ���Ľڵ�
 */
OAL_STATIC OAL_INLINE void oal_dlist_delete_entry(oal_dlist_head_stru *pst_entry)
{
    if (oal_unlikely(pst_entry == NULL)) {
        oal_warn_on(1);
        return;
    }

    if (oal_unlikely(oal_any_null_ptr2(pst_entry->pst_next, pst_entry->pst_prev))) {
        return;
    }

    oal_dlist_delete(pst_entry->pst_prev, pst_entry->pst_next);
    pst_entry->pst_next = OAL_PTR_NULL;
    pst_entry->pst_prev = OAL_PTR_NULL;
}

/*
 * �� �� ��  : oal_dlist_delete_head
 * ��������  : ��˫������ͷ��ɾ��һ���ڵ�,���ж������Ƿ�Ϊ�գ��������ͷ��ڴ� ��ע��
 */
OAL_STATIC OAL_INLINE oal_dlist_head_stru *oal_dlist_delete_head(oal_dlist_head_stru *pst_head)
{
    oal_dlist_head_stru *pst_node = NULL;

    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return NULL;
    }

    pst_node = pst_head->pst_next;

    oal_warn_on(pst_node == pst_head);
    oal_warn_on(pst_node == OAL_PTR_NULL);

    oal_dlist_delete_entry(pst_node);

    return pst_node;
}

/*
 * �� �� ��  : oal_dlist_delete_tail
 * ��������  : ��˫������ͷ��ɾ��һ���ڵ�,���ж������Ƿ�Ϊ�գ��������ͷ��ڴ� ��ע��
 */
OAL_STATIC OAL_INLINE oal_dlist_head_stru *oal_dlist_delete_tail(oal_dlist_head_stru *pst_head)
{
    oal_dlist_head_stru *pst_node = NULL;
    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return NULL;
    }
    pst_node = pst_head->pst_prev;

    oal_warn_on(pst_node == pst_head);
    oal_warn_on(pst_node == OAL_PTR_NULL);

    oal_dlist_delete_entry(pst_node);

    return pst_node;
}

/*
 * �� �� ��  : oal_dlist_join_tail
 * ��������  : ������2 ��������1��β��
 */
OAL_STATIC OAL_INLINE void oal_dlist_join_tail(oal_dlist_head_stru *pst_head1, oal_dlist_head_stru *pst_head2)
{
    oal_dlist_head_stru *pst_dlist1_tail = NULL;
    oal_dlist_head_stru *pst_dlist2_tail = NULL;
    oal_dlist_head_stru *pst_dlist2_first = NULL;

    if (oal_unlikely((pst_head1 == NULL) || (pst_head2 == NULL))) {
        oal_warn_on(1);
        return;
    }

    pst_dlist1_tail = pst_head1->pst_prev;
    pst_dlist2_tail = pst_head2->pst_prev;
    pst_dlist2_first = pst_head2->pst_next;
    pst_dlist1_tail->pst_next = pst_dlist2_first;
    pst_dlist2_first->pst_prev = pst_dlist1_tail;
    pst_head1->pst_prev = pst_dlist2_tail;
    pst_dlist2_tail->pst_next = pst_head1;
}

/*
 * �� �� ��  : oal_dlist_jion_head
 * ��������  : ������2 ��������1��ͷ�� Ҳ�����ڽ������� ����������ָ���ڵ��
 */
OAL_STATIC OAL_INLINE void oal_dlist_join_head(oal_dlist_head_stru *pst_head1, oal_dlist_head_stru *pst_head2)
{
    oal_dlist_head_stru *pst_head2_first = NULL;
    oal_dlist_head_stru *pst_head2_tail = NULL;
    oal_dlist_head_stru *pst_head1_first = NULL;

    if (oal_unlikely((pst_head1 == NULL) || (pst_head2 == NULL))) {
        oal_warn_on(1);
        return;
    }

    if (oal_dlist_is_empty(pst_head2)) {
        return;
    }

    pst_head2_first = pst_head2->pst_next;
    pst_head2_tail = pst_head2->pst_prev;
    pst_head1_first = pst_head1->pst_next;

    pst_head1->pst_next = pst_head2_first;
    pst_head2_first->pst_prev = pst_head1;
    pst_head2_tail->pst_next = pst_head1_first;
    pst_head1_first->pst_prev = pst_head2_tail;
}

/*
 * �� �� ��  : oal_dlist_remove_head
 * ��������  : ������2�дӵ�һ��Ԫ�ص�pst_last_dscr_entryԪ��ժ���� ���������1��ͷ��
 * �������  :  pst_head1 :����ͷ1, ������
 *              pst_head2 :����ͷ2
 *              pst_last_entry : ����2�е�Ԫ��
 *              Ĭ����ζ���NULL
 */
OAL_STATIC OAL_INLINE void oal_dlist_remove_head(oal_dlist_head_stru *pst_head1,
                                                 oal_dlist_head_stru *pst_head2,
                                                 oal_dlist_head_stru *pst_last_entry)
{
    if (oal_unlikely((pst_head1 == NULL) || (pst_head2 == NULL) || (pst_last_entry == NULL))) {
        oal_warn_on(1);
        return;
    }

    /* ��pst_head1��ֵ */
    pst_head1->pst_next = pst_head2->pst_next;
    pst_head1->pst_prev = pst_last_entry;

    pst_head2->pst_next = pst_last_entry->pst_next;
    /* pst_last_entryΪpst_head2�����һ����Ա */
    if (pst_last_entry->pst_next == pst_head2) {
        pst_head2->pst_prev = pst_head2;
    } else { /* pst_last_entry��pst_head2�����һ����Ա */
        ((oal_dlist_head_stru *)(pst_last_entry->pst_next))->pst_prev = pst_head2;
    }

    pst_last_entry->pst_next = pst_head1;
    /* pst_last_entryΪpst_head2�е�һ����Ա */
    if (pst_last_entry->pst_prev == pst_head2) {
        pst_last_entry->pst_prev = pst_head1;
    }
}

#endif /* end of oal_list.h */
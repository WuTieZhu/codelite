//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef __m_dataviewTemplatesModel_GUARD__H__
#define __m_dataviewTemplatesModel_GUARD__H__

#include <wx/variant.h>
#include <wx/dataview.h>
#include <algorithm>
#include <wx/clntdata.h>

class m_dataviewTemplatesModel_Node
{
protected:
    wxVector<wxVariant>        m_data;
    m_dataviewTemplatesModel_Node*           m_parent;
    wxVector<m_dataviewTemplatesModel_Node*> m_children;
    bool                       m_isContainer;
    wxClientData*              m_clientData;

public:
    m_dataviewTemplatesModel_Node()
        : m_parent(NULL)
        , m_isContainer(false)
        , m_clientData(NULL)
    {}
    virtual ~m_dataviewTemplatesModel_Node() {
        if ( m_clientData ) {
            delete m_clientData;
            m_clientData = NULL;
        }
        m_data.clear();

        // Delete our children
        // since the deletion of a child may alter its parent m_children array
        // we use a temporary vector for the loop
        wxVector<m_dataviewTemplatesModel_Node*> tmpChildren = m_children;
        while ( !tmpChildren.empty() ) {
            delete (*tmpChildren.begin());
            tmpChildren.erase(tmpChildren.begin());
        }
        m_children.clear();

        // Remove us from the parent
        if ( m_parent ) {
            m_parent->RemoveChild(this);
        }
    }

    void SetIsContainer(bool b) {
        m_isContainer = b;
    }

    bool IsContainer() const {
        return m_isContainer;
    }

    /**
     * @brief remove a child from this node and free its memory
     * @param child
     */
    void DeleteChild(m_dataviewTemplatesModel_Node* child) {
        wxVector<m_dataviewTemplatesModel_Node*>::iterator iter = std::find(m_children.begin(), m_children.end(), child);
        if ( iter != m_children.end() ) {
            delete *iter;
            m_children.erase(iter);
        }
    }

    /**
     * @brief remove child from this node without freeing its memory
     * @param child
     */
    void RemoveChild(m_dataviewTemplatesModel_Node* child) {
        wxVector<m_dataviewTemplatesModel_Node*>::iterator iter = std::find(m_children.begin(), m_children.end(), child);
        if ( iter != m_children.end() ) {
            m_children.erase(iter);
        }
    }

    /**
     * @brief add child to this node
     */
    void AddChild(m_dataviewTemplatesModel_Node* child) {
        m_children.push_back(child);
        child->m_parent = this;
    }

    bool IsRoot() const {
        return m_parent == NULL;
    }

    // Setters / Getters
    void SetChildren(const wxVector<m_dataviewTemplatesModel_Node*>& children) {
        this->m_children = children;
    }
    void SetData(const wxVector<wxVariant>& data) {
        this->m_data = data;
    }
    void SetParent(m_dataviewTemplatesModel_Node* parent) {
        this->m_parent = parent;
    }
    const wxVector<m_dataviewTemplatesModel_Node*>& GetChildren() const {
        return m_children;
    }
    wxVector<m_dataviewTemplatesModel_Node*>& GetChildren() {
        return m_children;
    }
    const wxVector<wxVariant>& GetData() const {
        return m_data;
    }
    wxVector<wxVariant>& GetData() {
        return m_data;
    }
    m_dataviewTemplatesModel_Node* GetParent() {
        return m_parent;
    }

    void SetClientObject(wxClientData *data) {
        if ( m_clientData ) {
            delete m_clientData;
        }
        m_clientData = data;
    }

    wxClientData* GetClientObject() const {
        return m_clientData;
    }
};

//////////////////////////////////////////////
// The TreeListCtrl model
//////////////////////////////////////////////

class m_dataviewTemplatesModel : public wxDataViewModel
{
protected:
    wxVector<m_dataviewTemplatesModel_Node*> m_data;
    unsigned int m_colCount;

public:
    m_dataviewTemplatesModel();
    virtual ~m_dataviewTemplatesModel();

    void SetColCount(unsigned int colCount) {
        this->m_colCount = colCount;
    }
    void SetData(const wxVector<m_dataviewTemplatesModel_Node*> data) {
        this->m_data = data;
    }
    unsigned int GetColCount() const {
        return m_colCount;
    }
    const wxVector<m_dataviewTemplatesModel_Node*>& GetData() const {
        return m_data;
    }
    wxVector<m_dataviewTemplatesModel_Node*>& GetData() {
        return m_data;
    }

    virtual bool HasContainerColumns (const wxDataViewItem& item) const {
        return false;
    }

protected:
    // Make the functions below 'virtual' so the user may override them
    virtual unsigned int GetChildren(const wxDataViewItem& item, wxDataViewItemArray& children) const;
    virtual unsigned int GetColumnCount() const;
    virtual wxString GetColumnType(unsigned int col) const;
    virtual wxDataViewItem GetParent(const wxDataViewItem& item) const;
    virtual bool IsContainer(const wxDataViewItem& item) const;
    virtual void GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const;
    virtual bool SetValue(const wxVariant &variant, const wxDataViewItem &item, unsigned int col);

protected:
    // Helpers
    wxDataViewItem DoAppendItem(const wxDataViewItem& parent, const wxVector<wxVariant>& data, bool isContainer, wxClientData *clientData = NULL);
    wxDataViewItem DoInsertItem(const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, bool isContainer, wxClientData *clientData);
public:
    /**
     * @brief Append a line to the model
     * clientData will be owned by the model once added (i.e. the clientData must be allocated on the heap and it will be freed by the model)
     */
    virtual wxDataViewItem AppendItem(const wxDataViewItem& parent, const wxVector<wxVariant>& data, wxClientData *clientData = NULL);

    /**
     * @brief Append a line to the model
     * clientData will be owned by the model once added (i.e. the clientData must be allocated on the heap and it will be freed by the model)
     */
    virtual wxDataViewItem AppendContainer(const wxDataViewItem& parent, const wxVector<wxVariant>& data, wxClientData *clientData = NULL);

    /**
     * @brief Append a lines to the model
     */
    virtual wxDataViewItemArray AppendItems(const wxDataViewItem& parent, const wxVector<wxVector<wxVariant> >& data);

    /**
     * @brief delete an item and all its children
     * @param parent
     */
    virtual void DeleteItem(const wxDataViewItem& item);

    /**
     * @brief delete an item
     * @param parent
     */
    virtual void DeleteItems(const wxDataViewItem& parent, const wxDataViewItemArray& items);
    
    /**
     * @brief update an item data + client-data
     */
    virtual void UpdateItem(const wxDataViewItem& item, const wxVector<wxVariant>& data);
    
    /**
     * @brief insert an item into the model before 'insertBeforeMe' item. Return the newly inserted item on success
     */
    virtual wxDataViewItem InsertItem     (const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, wxClientData *clientData = NULL);
    
    /**
     * @brief insert a container (item with children) into the model before 'insertBeforeMe' item. Return the newly inserted item on success
     */
    virtual wxDataViewItem InsertContainer(const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, wxClientData *clientData = NULL);
    
    /**
     * @brief clear the control and delete all its content
     */
    virtual void Clear();

    virtual bool IsEmpty() const;
    
    /**
     * @brief returns the client data associated with this item
     **/
    wxClientData* GetClientObject(const wxDataViewItem& item) const;
    
    /**
     * @brief set the client data for an item. The item data will be freed by the model
     */
    void SetClientObject(const wxDataViewItem& item, wxClientData *data);
    
    /**
     * @brief returns the item columsn data
     */
    wxVector<wxVariant> GetItemColumnsData(const wxDataViewItem& item) const;
};
#endif // __m_dataviewTemplatesModel_GUARD__H__
